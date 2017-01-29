//============================================================================
// Name        : UDPReader.cpp
// Author      : Rodolfo Lam
// Version     :
// Copyright   : (C) 2016 Rodolfo Lam. All Rights Reserved.
// Description : Get one DATA-type package and display its contents.
//============================================================================

#include "Graphics/Screen.h"
#include "Network/MessageParser.h"
#include "Util/Math/Vec2D.h"

#include <array>
#include <iostream>
#include <istream>
#include <unordered_map>

#include <Poco/ByteOrder.h>
#include <Poco/Exception.h>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>

using Poco::ByteOrder;

int main(int argc, char** argv) {
    al_init();

    RL::Graphics::Screen screen;

    Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 49003);
    Poco::Net::DatagramSocket dgs;
    try {
        dgs.bind(sa, false);
    } catch (const Poco::Exception &e) {
        std::cerr
                << "FATAL ERROR: Is the application already running? Port could not be opened. Details: "
                << e.message() << std::endl;
        return EXIT_FAILURE;
    }

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
        screen.flipScreen(); // Actually, this might be better placed at the end.

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

    return EXIT_SUCCESS;

}
