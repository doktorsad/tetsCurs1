#pragma once
#ifndef TRANSPORT_VEHICLE_IN_AIR_H
#define TRANSPORT_VEHICLE_IN_AIR_H
#include "ITransportAir.h"
class TransportVehicleInAir : public ITransportAir {
protected:
    virtual ~TransportVehicleInAir() = default;
    double shortening_the_distance;
    TransportVehicleInAir() = default;
    std::string get_name() const override final;
    std::string get_specialization()  const override final;
    int get_speed() const override final;
    double get_shortening_the_distatnce() const override final;
};
#endif