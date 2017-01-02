/*
 * MessageParser.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: rlam1
 */

#include <cstring>
#include "MessageParser.h"

namespace RL {
namespace Network {

MessageParser::MessageParser() {
    status = 0;
}

MessageParser::~MessageParser() {
}

bool MessageParser::LastPacketParseCorrect() const {
    return (status == 0) ? true : false;
}

int MessageParser::LastPacketParseStatusCode() const {
    return status;
}

void MessageParser::ParsePacket(
        const std::unordered_map<Poco::Int32, float[8]>& map,
        std::array<Poco::UInt8, NETMESSAGE_SIZE>& buffer, int bytesReceived) {

    int rows_received = (bytesReceived - 5) / 36; //
    if (rows_received < 1) {
        status = 1;
        return;
    }
    std::string PacketHeader; // TODO: Compare the packet header to real header.

    for (int i = 0; i < rows_received; i++) {
        Poco::Int32 type = parseIntfromBuffer(&buffer.at((i * 36) + 5));
    }
}

} /* namespace Network */
} /* namespace RL */
