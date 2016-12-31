/*
 * DATA_message.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: rlam1
 */

#include "DATA_message.hpp"
#include <cstring>

using Poco::ByteOrder;

Poco::Int32 rl::parseIntfromBuffer(Poco::UInt8 buffer[4]) {
	Poco::Int32 a;

	a = Poco::Int32(
			(Poco::UInt8) (buffer[0]) << 24 | (Poco::UInt8) (buffer[1]) << 16
					| (Poco::UInt8) (buffer[2]) << 8
					| (Poco::UInt8) (buffer[3]));

	Poco::Int32 retval = ByteOrder::fromNetwork(a);

	return retval;
}

float rl::parseFloatfromBuffer(Poco::UInt8 buffer[4]) {
	static_assert(sizeof(float) == sizeof(Poco::Int32), "Float is not 4 bytes");

	Poco::Int32 temp = 0;
	temp =
			((buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8)
					| buffer[3]);

	Poco::Int32 preRetval = ByteOrder::fromNetwork(temp);
	float retval; /* = reinterpret_cast<float &>(preRetval);*/ //This causes strict aliasing warning!
	std::memcpy(&retval, &preRetval, sizeof(retval));

	return retval;
}


