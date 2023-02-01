#include "TransportVehicleGround.h"

int TransportVehicleGround::get_time_before_bedtime() const  { return this->time_befor_bedtime; }
double TransportVehicleGround::get_this_sleep_time() const  { return this->sleep_time; }
std::string TransportVehicleGround::get_name() const  { return this->name; }
std::string TransportVehicleGround::get_specialization() const  { return this->specialization; }
int TransportVehicleGround::get_speed() const  { return speed; }
double TransportVehicleGround::get_update_sleep() const  { return 0; }
double TransportVehicleGround::get_update_sleep_second() const  { return 0; }