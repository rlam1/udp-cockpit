/*
 * Copyright (c) 2018 Rodolfo Lam. All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "Graphics/Screen.h"
#include "Network/MessageParser.h"
#include "Util/Math/Vec2D.h"

#include <array>
#include <iomanip>
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
void tempFullscreen(RL::Graphics::Screen& scr);

int main(int argc, char** argv) {
    al_init();
    al_install_keyboard();

    RL::Graphics::Screen screen;
    screen.toggleFullscreenMode();

    Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 49003);
    Poco::Net::DatagramSocket dgs;
    dgs.setBlocking(false);
    try {
        dgs.bind(sa, false);
    } catch (const Poco::Exception &e) {
        std::cerr
                << "FATAL ERROR: Is the application already running? Port could not be opened. Details: "
                << e.message() << std::endl;
        return -1;
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
        int n = 0;

        try {
            n = dgs.receiveFrom(buffer.data(), RL::Network::NETMESSAGE_SIZE,
                    sender);
        } catch (Poco::TimeoutException &e) {
            // Just continue trying
        }

        parser.ParsePacket(parsedData, buffer, n);
        bool success = parser.LastPacketParseCorrect();

        std::stringstream debText;
        debText << "Last Packet time: " << std::setprecision(4) << std::setw(6)
                << al_get_time() << " | Status: "<< success << " | Size: "
                << n;

        screen.processCommands(RL::Math::Vec2D<float>(), debText.str());

        screen.flipScreen(); // Actually, this might be better placed at the end.

        tempFullscreen(screen);
        exit = waitforEscKey();
    }

    return EXIT_SUCCESS;

}

void tempFullscreen(RL::Graphics::Screen& scr) {
    ALLEGRO_KEYBOARD_STATE state;
        al_get_keyboard_state(&state);

        if(al_key_down(&state, ALLEGRO_KEY_F)) {
            scr.toggleFullscreenMode();
        }
}

bool waitforEscKey() {
    ALLEGRO_KEYBOARD_STATE state;
    al_get_keyboard_state(&state);

    return al_key_down(&state, ALLEGRO_KEY_ESCAPE);
}
