//============================================================================
// Name        : UDPReader.cpp
// Author      : Rodolfo Lam
// Version     :
// Copyright   : (C) 2016 Rodolfo Lam. All Rights Reserved.
// Description : Get one DATA-type package and display its contents.
//============================================================================
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/ByteOrder.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <array>

using Poco::ByteOrder;

constexpr int NETMESSAGE_SIZE = 1024;

struct alignas(4) xMessage_struct {
	Poco::Int8 header[5];
	Poco::Int32 myIndex;
	float data[8];
};

Poco::Int32 parseIntfromBuffer(Poco::UInt8 buffer[4]) {
	Poco::Int32 a;

	a = Poco::Int32(
			(Poco::UInt8) (buffer[0]) << 24 | (Poco::UInt8) (buffer[1]) << 16
					| (Poco::UInt8) (buffer[2]) << 8
					| (Poco::UInt8) (buffer[3]));

	Poco::Int32 retval = ByteOrder::fromNetwork(a);

	return retval;
}

float parseFloatfromBuffer(Poco::UInt8 buffer[4]) {
	Poco::Int32 temp = 0;

	temp =
			((buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8)
					| buffer[3]);

	Poco::Int32 preRetval = ByteOrder::fromNetwork(temp);
	float retval; /* = reinterpret_cast<float &>(preRetval);*/ //This causes strict aliasing warning!
	static_assert(sizeof(float) == sizeof(Poco::Int32), "Float is not 4 bytes");
	std::memcpy(&retval, &preRetval, sizeof(retval));

	return retval;
}

int main(int argc, char** argv) {

	xMessage_struct *myData = new xMessage_struct;

	for (int i = 0; i < 8; i++) {
		myData->data[i] = 0.0f;
	}

	Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 49003);
	Poco::Net::DatagramSocket dgs(sa);

	std::array<Poco::UInt8, NETMESSAGE_SIZE> buffer;
	buffer.fill(0);

	for(;;) {
		Poco::Net::SocketAddress sender;
		int n = dgs.receiveFrom(buffer.data(), NETMESSAGE_SIZE, sender);

		std::memcpy(myData, buffer.data(), 4); // THE HEADER "DATA" message only
		myData->header[4] = '\0';

		myData->myIndex = parseIntfromBuffer(&buffer[5]);

		for (int i = 0; i < 8; ++i) {
			size_t offset = (i * 4) + 9; // i * 4(alignment) + 9(offset of first data[] member
			myData->data[i] = parseFloatfromBuffer(&buffer[offset]);
		}

		std::cout << "Bytes received: " << n << " - "
				<< myData->header << " Index: " << myData->myIndex
				<< std::endl;

		for (int i = 0; i < 8; i++) {
			std::cout << myData->data[i] << " ";
		}

		std::cout << std::endl;
	}

	delete myData;

	return 0;

}
