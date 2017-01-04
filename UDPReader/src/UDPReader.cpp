//============================================================================
// Name        : UDPReader.cpp
// Author      : Rodolfo Lam
// Version     :
// Copyright   : (C) 2016 Rodolfo Lam. All Rights Reserved.
// Description : Get one DATA-type package and display its contents.
//============================================================================
#include <iostream>
#include <array>
#include <unordered_map>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/ByteOrder.h>

#include "Network/MessageParser.h"

using Poco::ByteOrder;

int main(int argc, char** argv) {
    Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 49003);
    Poco::Net::DatagramSocket dgs(sa);

    std::array<Poco::UInt8, RL::Network::NETMESSAGE_SIZE> buffer;
    buffer.fill(0);

    std::unordered_map<RL::Network::DataTypesEnum, std::array<float, 8>,
            RL::Network::DataTypesEnumHash> parsedData;

    for (;;) {
        Poco::Net::SocketAddress sender;
        int n = dgs.receiveFrom(buffer.data(), RL::Network::NETMESSAGE_SIZE,
                sender);
    }

    return 0;

}
