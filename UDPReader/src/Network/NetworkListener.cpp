/*
 * NetworkListener.cpp
 *
 *  Created on: Apr 3, 2017
 *  Copyright (C) 2017 rlam1. See LICENSE file for more information
 *
 *  Description: 
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
