#pragma once
#ifndef ALL_TERRAIN_BOOTS_H
#define ALL_TERRAIN_BOOTS_H
#include "TransportVehicleGround.h"
class AllTerrainBoots : public TransportVehicleGround {
public:
    AllTerrainBoots();
    double get_update_sleep() const override final ;
};
#endif