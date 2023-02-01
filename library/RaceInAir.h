#pragma once
#ifndef RACE_IN_AIR_H
#define RACE_IN_AIR_H
#include "IRaceAir.h"
class RaceInAir : public IRaceAir {
protected:
    std::vector <std::shared_ptr<ITransportAir > > transports;
public:
    RaceInAir() = delete;
    RaceInAir(const int& distance) ;
    void bubble_sort_transport() override final;
    std::string get_name(const int& i) const override final ;
    int get_size() const override ;
    void set_magic_carpet() override final ;
    void set_eagle() override final ;
    void set_broomstick() override final ;
    double get_time(const int& i) const override final ;
};
#endif