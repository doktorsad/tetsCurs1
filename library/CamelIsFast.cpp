#include "CamelIsFast.h"

CamelIsFast::CamelIsFast() {
    this->speed = 40;
    this->time_befor_bedtime = 10;
    this->sleep_time = 5;
    this->name = "Camel Fast";
    this->specialization = "ground";
}
double CamelIsFast::get_update_sleep() const  { return 6.5; }
double CamelIsFast::get_update_sleep_second() const  { return 8; }