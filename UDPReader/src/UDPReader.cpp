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
    parsedData.reserve(46);

    for (auto const &ref : RL::Network::Data_Index) {
        std::array<float, 8> ar;
        parsedData.emplace(std::make_pair(ref.second, std::move(ar)));
    }

    RL::Network::MessageParser parser;

    for (;;) {
        Poco::Net::SocketAddress sender;
        int n = dgs.receiveFrom(buffer.data(), RL::Network::NETMESSAGE_SIZE,
                sender);

        parser.ParsePacket(parsedData, buffer, n);
        if (parser.LastPacketParseCorrect()) {
            for (const auto &record : parsedData) {
                for (const auto &rows : record.second) {
                    std::cout << rows << ", ";
                }

                std::cout << std::endl;
            }
        } else {
            std::cerr << "ERROR: " << parser.LastPacketParseStatusCode()
                    << std::endl;
        }
    }

    return 0;

}
