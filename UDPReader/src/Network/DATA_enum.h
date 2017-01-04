/*
 * Data_enum.h
 *
 *  Created on: Jan 3, 2017
 *      Author: rlam1
 */

#ifndef NETWORK_DATA_ENUM_H_
#define NETWORK_DATA_ENUM_H_

namespace RL {
namespace Network {

enum class DataTypesEnum // DataIndex
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

} // namespace Network
} // namespace rl

#endif /* NETWORK_DATA_ENUM_H_ */
