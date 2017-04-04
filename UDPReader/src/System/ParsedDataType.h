/*
 * Types.h
 *
 *  Created on: Apr 3, 2017
 *  Copyright (C) 2017 rlam1. See LICENSE file for more information
 *
 *  Description: Definition of custom hashmap of parsed data
 */

#ifndef SYSTEM_PARSEDDATATYPE_H_
#define SYSTEM_PARSEDDATATYPE_H_

#include "Network/DATA_enum.h"

#include <array>
#include <unordered_map>

namespace RL {
namespace System {
    typedef std::unordered_map<RL::Network::DataTypesEnum,
            std::array<float, 8>,
            RL::Network::DataTypesEnumHash> data_hash;
}  // namespace System
}  // namespace RL



#endif /* SYSTEM_PARSEDDATATYPE_H_ */
