#pragma once
#ifndef TRANSPORT_VEHICLE_GROUND_H
#define TRANSPORT_VEHICLE_GROUND_H
#include "ITransportGround.h"
class TransportVehicleGround : public ITransportGround {
protected:
    virtual ~TransportVehicleGround() = default;
    int time_befor_bedtime;
    double sleep_time;
    TransportVehicleGround() = default;
    int get_time_before_bedtime() const override final;
    double get_this_sleep_time() const override final;
    std::string get_name() const override final;
    std::string get_specialization() const override final;
    int get_speed() const override final;
    double get_update_sleep() const override;
    double get_update_sleep_second() const override;
};
#endif