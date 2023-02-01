#pragma once
#ifndef MAGIC_CARPET_H
#define MAGIC_CARPET_H
#include "TransportVehicleInAir.h"
class MagicCarpet : public TransportVehicleInAir {
public:
    MagicCarpet(const int& distance);
};
#endif