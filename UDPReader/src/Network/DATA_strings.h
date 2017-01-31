/*
 * DATA_strings.h
 *
 *  Created on: Jan 29, 2017
 *      Author: rlam1
 */

#ifndef NETWORK_DATA_STRINGS_H_
#define NETWORK_DATA_STRINGS_H_

#include "DATA_enum.h"

#include <map>
#include <string>

namespace RL {
namespace Network {

const std::map<DataTypesEnum, std::string> Data_Labels = {
    { DataTypesEnum::frame_rate,         "Framerate" },
    { DataTypesEnum::times,              "Times" },
    { DataTypesEnum::speeds,             "Knots & MPH" },
    { DataTypesEnum::speeds2,            "Misc. Speed" },
    { DataTypesEnum::atmosphere_weather,"Gen. Atmosphere" },
    { DataTypesEnum::atmosphere_aircraft,"A/C Atmosphere"},
    { DataTypesEnum::drag_surfaces,      "Trim and drag surf."},
    { DataTypesEnum::gear_brakes,        "LDG & brakes"},
    { DataTypesEnum::pitch_roll_heading, "Pitch, Roll, Heading"},
    { DataTypesEnum::AoA_sideslip_paths, "AoA & Slips" },
    { DataTypesEnum::magnetic_compass,   "Magnetic Compass" },
    { DataTypesEnum::lat_long_alt,       "Coords & Altitude" },
    { DataTypesEnum::engine_RPM,         "Engine RPM" },
    { DataTypesEnum::prop_RPM,           "Propeller RPM" },
    { DataTypesEnum::prop_pitch,         "Propeller Pitch" },
    { DataTypesEnum::N1,                 "N1" },
    { DataTypesEnum::N2,                 "N2" },
    { DataTypesEnum::manifold_pressure,  "Manifold Press." },
    { DataTypesEnum::EPR,                "EPR" },
    { DataTypesEnum::fuel_flow,          "Fuel Flow lb/h" },
    { DataTypesEnum::ITT,                "ITT" },
    { DataTypesEnum::EGT,                "EGT" },
    { DataTypesEnum::CHT,                "CHT" },
    { DataTypesEnum::oil_pressure,       "Oil Pressure" },
    { DataTypesEnum::oil_temperature,    "Oil Temperature" },
    { DataTypesEnum::fuel_pressure,      "Fuel Pressure" },
    { DataTypesEnum::generator_amps,     "Generator Load" },
    { DataTypesEnum::battery_amps,       "Battery Load" },
    { DataTypesEnum::battery_volts,      "Battery Volts" },
    { DataTypesEnum::gear_deployment,    "Gear Deployment" },
    { DataTypesEnum::COM_1_2_freqs,      "COM 1 & 2" },
    { DataTypesEnum::NAV_1_2_freqs,      "NAV 1 & 2" },
    { DataTypesEnum::NAV_1_2_OBS,        "NAV OBS" },
    { DataTypesEnum::NAV_1_deflections,  "NAV1 Deflections" },
    { DataTypesEnum::NAV_2_deflections,  "NAV2 Deflections" },
    { DataTypesEnum::ADF_1_2_status,     "ADF 1 & 2" },
    { DataTypesEnum::DME_status,         "DME Data" },
    { DataTypesEnum::GPS_status,         "GPS Data" },
    { DataTypesEnum::XPNDR_status,       "XPNDR" },
    { DataTypesEnum::MARKER_status,      "Marker Beacons" },
    { DataTypesEnum::annun_general1,     "General Annunciators" },
    { DataTypesEnum::annun_general2,     "System Annunciators" },
    { DataTypesEnum::annun_engine,       "Engine Annunciators" },
    { DataTypesEnum::annun_warning,      "Warning Annunciators" },
    { DataTypesEnum::stat_climb,         "Climb statistics" },
    { DataTypesEnum::stat_cruise,        "Cruise Statistics" }
};

} // namespace Network
} // namespace rl

#endif /* NETWORK_DATA_STRINGS_H_ */
