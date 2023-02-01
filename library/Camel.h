#pragma once
#ifndef CAMEL_H
#define CAMEL_H
#include "TransportVehicleGround.h"
class Camel : public TransportVehicleGround {
public:
    Camel() ;
    double get_update_sleep() const override final ;
};
#endif