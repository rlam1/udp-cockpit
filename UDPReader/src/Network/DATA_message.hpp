/*
 * DATA_message.hpp
 *
 *  Created on: Dec 12, 2016
 *      Author: rlam1
 */
#ifndef DATA_MESSAGE_HPP_
#define DATA_MESSAGE_HPP_
#include <Poco/Types.h>
#include <Poco/ByteOrder.h>

namespace RL {
namespace Network {

constexpr Poco::Int8 header[5] = "DATA";

enum class Data_Index
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

struct alignas(4) data_struct {
	Data_Index myIndex;
	float data[8];
};

Poco::Int32 parseIntfromBuffer(Poco::UInt8 buffer[4]);
float parseFloatfromBuffer(Poco::UInt8 buffer[4]);

} // namespace Network
} // namespace rl

#endif /* DATA_MESSAGE_HPP_ */
