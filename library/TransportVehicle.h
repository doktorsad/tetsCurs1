#pragma once
#ifndef TRANSPORT_VEHICLE_H
#define TRANSPORT_VEHICLE_H
#include <string>
#include <memory>
class TransportVehicle {
public:
    virtual std::string get_name() const = 0;
protected:
    int speed;
    std::string name;
    std::string specialization;
    virtual ~TransportVehicle() = default;
    TransportVehicle& operator=(const TransportVehicle&) = delete;
    TransportVehicle() = default;
};
#endif
