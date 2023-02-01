#include "TransportVehicleInAir.h"

std::string TransportVehicleInAir::get_name() const  { return this->name; }
std::string TransportVehicleInAir::get_specialization()  const  { return this->specialization; }
int TransportVehicleInAir::get_speed() const  { return this->speed; }
double TransportVehicleInAir::get_shortening_the_distatnce() const { return this->shortening_the_distance; }