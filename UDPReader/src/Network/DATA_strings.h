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

typedef DataTypesEnum data;

std::map<DataTypesEnum, std::string> Data_Labels = {
    { data::frame_rate,         "Framerate" },
    { data::times,              "Times" },
    { data::speeds,             "Knots & MPH" },
    { data::speeds2,            "Misc. Speed" },
    { data::atmosphere_weather,"Gen. Atmosphere" },
    { data::atmosphere_aircraft,"A/C Atmosphere"},
    { data::drag_surfaces,      "Trim and drag surf."},
    { data::gear_brakes,        "LDG & brakes"},
    { data::pitch_roll_heading, "Pitch, Roll, Heading"},
    { data::AoA_sideslip_paths, "AoA & Slips" },
    { data::magnetic_compass,   "Magnetic Compass" },
    { data::lat_long_alt,       "Coords & Altitude" },
    { data::engine_RPM,         "Engine RPM" },
    { data::prop_RPM,           "Propeller RPM" },
    { data::prop_pitch,         "Propeller Pitch" },
    { data::N1,                 "N1" },
    { data::N2,                 "N2" },
    { data::manifold_pressure,  "Manifold Press." },
    { data::EPR,                "EPR" },
    { data::fuel_flow,          "Fuel Flow lb/h" },
    { data::ITT,                "ITT" },
    { data::EGT,                "EGT" },
    { data::CHT,                "CHT" },
    { data::oil_pressure,       "Oil Pressure" },
    { data::oil_temperature,    "Oil Temperature" },
    { data::fuel_pressure,      "Fuel Pressure" },
    { data::generator_amps,     "Generator Load" },
    { data::battery_amps,       "Battery Load" },
    { data::battery_volts,      "Battery Volts" },
    { data::gear_deployment,    "Gear Deployment" },
    { data::COM_1_2_freqs,      "COM 1 & 2" },
    { data::NAV_1_2_freqs,      "NAV 1 & 2" },
    { data::NAV_1_2_OBS,        "NAV OBS" },
    { data::NAV_1_deflections,  "NAV1 Deflections" },
    { data::NAV_2_deflections,  "NAV2 Deflections" },
    { data::ADF_1_2_status,     "ADF 1 & 2" },
    { data::DME_status,         "DME Data" },
    { data::GPS_status,         "GPS Data" },
    { data::XPNDR_status,       "XPNDR" },
    { data::MARKER_status,      "Marker Beacons" },
    { data::annun_general1,     "General Annunciators" },
    { data::annun_general2,     "System Annunciators" },
    { data::annun_engine,       "Engine Annunciators" },
    { data::annun_warning,      "Warning Annunciators" },
    { data::stat_climb,         "Climb statistics" },
    { data::stat_cruise,        "Cruise Statistics" }
};

} // namespace Network
} // namespace rl

#endif /* NETWORK_DATA_STRINGS_H_ */
