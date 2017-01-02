/*
 * DATA_message.hpp
 *
 *  Created on: Dec 12, 2016
 *      Author: rlam1
 */
#ifndef DATA_MESSAGE_HPP_
#define DATA_MESSAGE_HPP_
#include <string>
#include <unordered_map>
#include <Poco/Types.h>
#include <Poco/ByteOrder.h>

namespace RL {
namespace Network {

enum DI // DataIndex
    : Poco::Int32 {
        frame_rate,
    times,
    speeds = 3,
    speeds2,
    athmosphere_weather,
    athmosphere_aircraft,
    drag_surfaces = 13,
    gear_brakes,
    pitch_roll_heading = 17,
    AoA_sideslip_paths,
    magnetic_compass,
    lat_long_alt,
    engine_RPM = 37,
    prop_RPM,
    prop_pitch,
    N1 = 41,
    N2,
    manifold_pressure,
    EPR,
    fuel_flow,
    ITT,
    EGT,
    CHT,
    oil_pressure,
    oil_temperature,
    fuel_pressure,
    generator_amps,
    battery_amps,
    battery_volts,
    gear_deployment = 67,
    COM_1_2_freqs = 96,
    NAV_1_2_freqs,
    NAV_1_2_OBS,
    NAV_1_deflections,
    NAV_2_deflections,
    ADF_1_2_status,
    DME_status,
    GPS_status,
    XPNDR_status,
    MARKER_status,
    annun_general1 = 113,
    annun_general2,
    annun_engine,
    annun_warning = 127,
    stat_climb = 132,
    stat_cruise
};

const std::string header = "DATA";
const std::unordered_map<std::string, int> Data_Index1 {
        { "frame_rate", DI::frame_rate },
        { "times", DI::times },
        { "speeds", DI::speeds },
        { "speeds2", DI::speeds2 },
        { "athmosphere_weather", DI::athmosphere_weather },
        { "athmosphere_aircraft", DI::athmosphere_aircraft },
        { "drag_surfaces", DI::drag_surfaces },
        { "gear_brakes", DI::gear_brakes },
        { "pitch_roll_heading", DI::pitch_roll_heading },
        { "AoA_sideslip_paths", DI::AoA_sideslip_paths },
        { "magnetic_compass", DI::magnetic_compass },
        { "lat_long_alt", DI::lat_long_alt },
        { "engine_RPM", DI::engine_RPM },
        { "prop_RPM", DI::prop_RPM },
        { "prop_pitch", DI::prop_pitch },
        { "N1", DI::N1 },
        { "N2", DI::N2 },
        { "manifold_pressure", DI::manifold_pressure },
        { "EPR", DI::EPR },
        { "fuel_flow", DI::fuel_flow },
        { "ITT", DI::ITT },
        { "EGT", DI::EGT },
        { "CHT", DI::CHT },
        { "oil_pressure", DI::oil_pressure },
        { "oil_temperature", DI::oil_temperature },
        { "fuel_pressure", DI::fuel_pressure },
        { "generator_amps", DI::generator_amps },
        { "battery_amps", DI::battery_amps },
        { "battery_volts", DI::battery_volts },
        { "gear_deployment", DI::gear_deployment },
        { "COM_1_2_freqs", DI::COM_1_2_freqs },
        { "NAV_1_2_freqs", DI::NAV_1_2_freqs },
        { "NAV_1_2_OBS", DI::NAV_1_2_OBS },
        { "NAV_1_deflections", DI::NAV_1_deflections },
        { "NAV_2_deflections", DI::NAV_2_deflections },
        { "ADF_1_2_status", DI::ADF_1_2_status },
        { "DME_status", DI::DME_status },
        { "GPS_status", DI::GPS_status },
        { "XPNDR_status", DI::XPNDR_status },
        { "MARKER_status", DI::MARKER_status },
        { "annun_general1", DI::annun_general1 },
        { "annun_general2", DI::annun_general2 },
        { "annun_engine", DI::annun_engine },
        { "annun_warning", DI::annun_warning },
        { "stat_climb", DI::stat_climb },
        { "stat_cruise", DI::stat_cruise } };

struct alignas(4) data_struct {
    Poco::Int32 myIndex;
    float data[8];
};

Poco::Int32 parseIntfromBuffer(Poco::UInt8 buffer[4]);
float parseFloatfromBuffer(Poco::UInt8 buffer[4]);

} // namespace Network
} // namespace rl

#endif /* DATA_MESSAGE_HPP_ */
