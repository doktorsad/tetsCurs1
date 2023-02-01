#pragma once
#ifndef CAMEL_IS_FAST_H
#define CAMEL_IS_FAST_H
#include "TransportVehicleGround.h"
class CamelIsFast : public TransportVehicleGround {
public:
    CamelIsFast();
    double get_update_sleep() const override final ;
    double get_update_sleep_second() const override final ;
};
#endif