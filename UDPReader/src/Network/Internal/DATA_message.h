/*
 * DATA_message.hpp
 *
 *  Created on: Dec 12, 2016
 *      Author: rlam1
 */
#ifndef DATA_MESSAGE_HPP_
#define DATA_MESSAGE_HPP_

#include "Network/DATA_enum.h"

#include <string>
#include <unordered_map>
#include <Poco/Types.h>
#include <Poco/ByteOrder.h>

namespace RL {
namespace Network {

const std::unordered_map<Poco::Int32, DataTypesEnum> Data_Index = {
        { 0, DataTypesEnum::frame_rate },
        { 1, DataTypesEnum::times },
        { 3, DataTypesEnum::speeds },
        { 4, DataTypesEnum::speeds2 },
        { 5, DataTypesEnum::atmosphere_weather },
        { 6, DataTypesEnum::atmosphere_aircraft },
        { 13, DataTypesEnum::drag_surfaces },
        { 14, DataTypesEnum::gear_brakes },
        { 17, DataTypesEnum::pitch_roll_heading },
        { 18, DataTypesEnum::AoA_sideslip_paths },
        { 19, DataTypesEnum::magnetic_compass },
        { 20, DataTypesEnum::lat_long_alt },
        { 37, DataTypesEnum::engine_RPM },
        { 38, DataTypesEnum::prop_RPM },
        { 39, DataTypesEnum::prop_pitch },
        { 41, DataTypesEnum::N1 },
        { 42, DataTypesEnum::N2 },
        { 43, DataTypesEnum::manifold_pressure },
        { 44, DataTypesEnum::EPR },
        { 45, DataTypesEnum::fuel_flow },
        { 46, DataTypesEnum::ITT },
        { 47, DataTypesEnum::EGT },
        { 48, DataTypesEnum::CHT },
        { 49, DataTypesEnum::oil_pressure },
        { 50, DataTypesEnum::oil_temperature },
        { 51, DataTypesEnum::fuel_pressure },
        { 52, DataTypesEnum::generator_amps },
        { 53, DataTypesEnum::battery_amps },
        { 54, DataTypesEnum::battery_volts },
        { 67, DataTypesEnum::gear_deployment },
        { 96, DataTypesEnum::COM_1_2_freqs },
        { 97, DataTypesEnum::NAV_1_2_freqs },
        { 98, DataTypesEnum::NAV_1_2_OBS },
        { 99, DataTypesEnum::NAV_1_deflections },
        { 100, DataTypesEnum::NAV_2_deflections },
        { 101, DataTypesEnum::ADF_1_2_status },
        { 102, DataTypesEnum::DME_status },
        { 103, DataTypesEnum::GPS_status },
        { 104, DataTypesEnum::XPNDR_status },
        { 105, DataTypesEnum::MARKER_status },
        { 113, DataTypesEnum::annun_general1 },
        { 114, DataTypesEnum::annun_general2 },
        { 115, DataTypesEnum::annun_engine },
        { 127, DataTypesEnum::annun_warning },
        { 132, DataTypesEnum::stat_climb },
        { 133, DataTypesEnum::stat_cruise } };

constexpr char DataHeader[] = "DATA";

struct alignas(4) data_struct {
    Poco::Int32 myIndex;
    float data[8];
};

Poco::Int32 parseIntfromBuffer(const Poco::UInt8 buffer[4]);
float parseFloatfromBuffer(const Poco::UInt8 buffer[4]);

} // namespace Network
} // namespace rl

#endif /* DATA_MESSAGE_HPP_ */
