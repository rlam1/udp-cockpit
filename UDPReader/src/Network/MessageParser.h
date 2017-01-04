/*
 * MessageParser.h
 *
 *  Created on: Dec 31, 2016
 *      Author: rlam1
 */

#ifndef NETWORK_MESSAGEPARSER_H_
#define NETWORK_MESSAGEPARSER_H_

#include <unordered_map>
#include <array>
#include <Poco/Types.h>

#include "Internal/DATA_message.h"

namespace RL {
namespace Network {

constexpr int NETMESSAGE_SIZE = 4800;

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
    void ParsePacket(std::unordered_map<DataTypesEnum, float[8]> &map,
            std::array<Poco::UInt8, NETMESSAGE_SIZE> &buffer,
            int bytesReceived);

private:
    int status;
};

} /* namespace Network */
} /* namespace RL */

#endif /* NETWORK_MESSAGEPARSER_H_ */
