/*
 * DATA_message.hpp
 *
 *  Created on: Dec 12, 2016
 *      Author: rlam1
 */

#ifndef DATA_MESSAGE_HPP_
#define DATA_MESSAGE_HPP_

#include <Poco/Types.h>

namespace rl {

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
	engineRPM = 37,
	propRPM,
	propPitch,
	N1 = 41,
	N2,
	ManifoldPressure,
	EPR,
	FuelFlow,
	ITT,
	EGT,
	CHT,
	OilPressure,
	OilTemperature,
	FuelPressure,
	GeneratorAmps,
	BatteryAmps,
	BatteryVolts,
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

constexpr Poco::Int8 header[5] = "DATA";

} // namespace rl



#endif /* DATA_MESSAGE_HPP_ */
