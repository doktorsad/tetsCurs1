#pragma once
#ifndef I_TRANSPORT_AIR_H
#define I_TRANSPORT_AIR_H
#include "TransportVehicle.h"
class MagicCarpet;
class Eagle;
class Broomstick;
class ITransportAir : public TransportVehicle {
protected:
    virtual ~ITransportAir() = default;
    ITransportAir& operator=(const ITransportAir&) = delete;
    ITransportAir() = default;
public:
    virtual std::string get_name() const = 0;
    virtual std::string get_specialization() const = 0;
    virtual int get_speed() const = 0;
    virtual double get_shortening_the_distatnce() const = 0;

    std::shared_ptr<MagicCarpet> creat_magic_carpet(const int& distance);
    std::shared_ptr<Eagle> creat_eagle();
    std::shared_ptr<Broomstick> creat_broomstick(const int& distance);
};
#endif