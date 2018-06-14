/*
 * Copyright (c) 2018 Rodolfo Lam. All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 *
 *  Description: Handles incoming network traffic
 */

#ifndef NETWORK_NETWORKLISTENER_H_
#define NETWORK_NETWORKLISTENER_H_

#include "Network/MessageParser.h"
#include "System/ParsedDataType.h"

#include <array>
#include <unordered_map>

#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>

namespace RL {
namespace Network {

/* NetworkListener
 * ----------------------------------------------
 * Wraps the network code into a single location.
 * Class is responsible for handling the connection setup
 * and parsing of incoming packets. */
class NetworkListener {
public:
    NetworkListener();
    virtual ~NetworkListener();

    /* Listens on selected UDP port for new packet.
     * If found, store the data into the buffer.
     * Return the address of the sender. */
    Poco::Net::SocketAddress checkforPacket();

    int getLastPacketSize() const;

private:
    Poco::Net::SocketAddress receiveAddress;
    Poco::Net::DatagramSocket dataSocket;

    std::array<Poco::UInt8, RL::Network::NETMESSAGE_SIZE> buffer;

    RL::Network::MessageParser parser;
    int sizeOfLastPacket;
};

} /* namespace Network */
} /* namespace RL */

#endif /* NETWORK_NETWORKLISTENER_H_ */
