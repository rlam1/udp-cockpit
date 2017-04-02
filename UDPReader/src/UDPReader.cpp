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
#include <sstream>
#include <unordered_map>

#include <Poco/ByteOrder.h>
#include <Poco/Exception.h>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>

using Poco::ByteOrder;

bool waitforEscKey();

int main(int argc, char** argv) {
    al_init();
    al_install_keyboard();

    RL::Graphics::Screen screen;

    Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 49003);
    Poco::Net::DatagramSocket dgs;
    dgs.setBlocking(false);
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

    bool exit = false;

    while (exit != true) {
        Poco::Net::SocketAddress sender;
        int n;

        try {
            n = dgs.receiveFrom(buffer.data(), RL::Network::NETMESSAGE_SIZE,
                    sender);
        } catch (Poco::TimeoutException &e) {
            std::cerr << "[" << al_get_time() << "] " << "Timeout, no data received" << std::endl;
        }

        parser.ParsePacket(parsedData, buffer, n);
        bool success = parser.LastPacketParseCorrect();

        std::stringstream debText;
        debText << "Last Packet time: " << al_get_time() << " | Status: "
                << success << " | Size: " << n;

        screen.processCommands(RL::Math::Vec2D<float>(), debText.str());

        screen.flipScreen(); // Actually, this might be better placed at the end.

        exit = waitforEscKey();
    }

    return EXIT_SUCCESS;

}

bool waitforEscKey() {
    ALLEGRO_KEYBOARD_STATE state;
    al_get_keyboard_state(&state);

    if(&state == nullptr) {
        return false;
    }

    return al_key_down(&state, ALLEGRO_KEY_ESCAPE);
}
