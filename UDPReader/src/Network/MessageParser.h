/*
 * MessageParser.h
 *
 *  Created on: Dec 31, 2016
 *      Author: rlam1
 */

#ifndef NETWORK_MESSAGEPARSER_H_
#define NETWORK_MESSAGEPARSER_H_

#include "Internal\DATA_message.h"

#include <array>
#include <unordered_map>

#include <Poco/Types.h>

namespace RL {
namespace Network {

/* 4793 bytes is maximum with all 133 DATA fields active + 5 bytes of header.
 Rounded for additional buffer space in case its necessary. */
constexpr int NETMESSAGE_SIZE = 4800;

/* MessageParser
 * ----------------------------------------------
 * Implements a parser for X-Plane's DATA UDP message.
 * Information enters as a buffer of binary data and
 * returns as a hash table (unordered_map) for easy lookup
 * by another part of the program. */
class MessageParser {
public:
    MessageParser();
    virtual ~MessageParser();

    /* Returns false if any error happened
     * during the parsing of a structure.
     * Returns true otherwise. */
    bool LastPacketParseCorrect() const;

    /* Returns the exact code of the last
     * parse attempt.*/
    int LastPacketParseStatusCode() const;

    /* &map          - Updated to new values parsed.
     * &buffer       - Place from which data will be read from.
     * bytesReceived - Value returned from receiveFrom (POCO)
     *
     * This function also modifies internal status.*/
    void ParsePacket(
            std::unordered_map<DataTypesEnum, std::array<float, 8>,
                    DataTypesEnumHash> &map,
            const std::array<Poco::UInt8, NETMESSAGE_SIZE> &buffer,
            const int bytesReceived);

private:
    int status;
};

} /* namespace Network */
} /* namespace RL */

#endif /* NETWORK_MESSAGEPARSER_H_ */
