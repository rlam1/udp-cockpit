/*
 * MessageParser.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: rlam1
 */

#include <iostream>
#include <cstring>
#include <stdexcept>
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
        std::unordered_map<DataTypesEnum, float[8]>& map,
        std::array<Poco::UInt8, NETMESSAGE_SIZE>& buffer,
        int bytesReceived) {
    constexpr size_t headerSize = sizeof(DataHeader) / sizeof(DataHeader[0]);
    constexpr size_t structSize = sizeof(data_struct);

    static_assert(structSize == 36, "Misaligned data structure!");
    static_assert(headerSize == 5, "Internal header representation is not size 5");

    int rows_received = (bytesReceived - headerSize) / structSize;
    if (rows_received < 1) {
        status = 1;
        return;
    }

    char NetworkHeader[5];
    std::memcpy(NetworkHeader, buffer.data(), 5);
    std::string SNetworkHeader(NetworkHeader);
    if (SNetworkHeader.compare(DataHeader) != 0) {
        status = 1;
        return;
    }

    for (int i = 0; i < rows_received; i++) {
        try {
            Poco::Int32 typeKey = parseIntfromBuffer(
                    &buffer.at((i * structSize) + headerSize));

            DataTypesEnum key = Data_Index.at(typeKey);

            for (int j = 0; j < 8; j++) {

            }
        } catch (std::out_of_range &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
    }
}

} /* namespace Network */
} /* namespace RL */
