/*
 * Copyright (c) 2018 Rodolfo Lam. All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <Network\NetworkListener.h>

namespace RL {
namespace Network {

NetworkListener::NetworkListener() {
    receiveAddress = Poco::Net::SocketAddress(Poco::Net::IPAddress(), 49003);
    dataSocket.setBlocking(false);
    dataSocket.bind(receiveAddress, false);

    buffer.fill(0);

    sizeOfLastPacket = 0;
}

NetworkListener::~NetworkListener() {
    dataSocket.close();
}

Poco::Net::SocketAddress NetworkListener::checkforPacket() {
    Poco::Net::SocketAddress sender;

    try {
        sizeOfLastPacket = dataSocket.receiveFrom(buffer.data(),
                    RL::Network::NETMESSAGE_SIZE, sender);
    } catch (Poco::TimeoutException &e) {
        sizeOfLastPacket = 0;
    }

    return sender;
}

int NetworkListener::getLastPacketSize() const {
    return sizeOfLastPacket;
}

} /* namespace Network */
} /* namespace RL */
