#pragma once
#ifndef I_TRANSPORT_GROUND_H
#define I_TRANSPORT_GROUND_H
#include "TransportVehicle.h"
class Camel;
class CamelIsFast;
class Centaur;
class AllTerrainBoots;
class ITransportGround : public TransportVehicle {
protected:
    virtual ~ITransportGround() = default;
    ITransportGround& operator=(const ITransportGround&) = delete;
    ITransportGround() = default;
public:
    virtual std::string get_name() const = 0;
    virtual std::string get_specialization() const = 0;
    virtual int get_speed() const = 0;
    virtual int get_time_before_bedtime() const = 0;
    virtual double get_this_sleep_time() const = 0;
    virtual double get_update_sleep() const = 0;
    virtual double get_update_sleep_second() const = 0;

    std::shared_ptr<Camel> creat_camel();
    std::shared_ptr<CamelIsFast> creat_camel_is_fast();
    std::shared_ptr<Centaur> creat_centaur();
    std::shared_ptr<AllTerrainBoots> creat_all_terrain_boots();
};
#endif