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

#include "Network/DATA_message.hpp"

using Poco::ByteOrder;

/* 4793 bytes is maximum with all 133 DATA fields active + 5 bytes of header.
 Rounded for additional buffer space in case its necessary. */
constexpr int NETMESSAGE_SIZE = 4800;

struct alignas(4) xMessage_struct {
	Poco::Int8 header[5];
	Poco::Int32 myIndex;
	float data[8];
};

int main(int argc, char** argv) {
	xMessage_struct myData;

	for (int i = 0; i < 8; i++) {
		myData.data[i] = 0.0f;
	}

	Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 49003);
	Poco::Net::DatagramSocket dgs(sa);

	std::array<Poco::UInt8, NETMESSAGE_SIZE> buffer;
	buffer.fill(0);

	for(;;) {
		Poco::Net::SocketAddress sender;
		int n = dgs.receiveFrom(buffer.data(), NETMESSAGE_SIZE, sender);

		std::memcpy(&myData, buffer.data(), 4); // THE HEADER "DATA" message only
		myData.header[4] = '\0';

		myData.myIndex = RL::Network::parseIntfromBuffer(&buffer[5]);

		for (int i = 0; i < 8; ++i) {
			size_t offset = (i * 4) + 9; // i * 4(alignment) + 9(offset of first data[] member
			myData.data[i] = RL::Network::parseFloatfromBuffer(&buffer[offset]);
		}

		std::cout << "Bytes received: " << n << " - "
				<< myData.header
				<< " Index: " << myData.myIndex
				<< std::endl;

		for (int i = 0; i < 8; i++) {
			std::cout << myData.data[i] << " ";
		}

		std::cout << std::endl;
	}

	return 0;

}
