#pragma once
#ifndef BROOMSTICK_H
#define BROOMSTICK_H
#include "TransportVehicleInAir.h"
class Broomstick : public TransportVehicleInAir {
public:
    Broomstick() = delete;
    Broomstick(const int& distance);
};
#endif