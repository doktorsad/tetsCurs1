#pragma once
#ifndef RACE_ON_GROUND_H
#define RACE_ON_GROUND_H
#include "IRaceGround.h"
class RaceOnGround : public IRaceGround {
protected:
    std::vector <std::shared_ptr<ITransportGround > > transports;
public:
    RaceOnGround() = delete;
    RaceOnGround(const int& distance) ;
    void bubble_sort_transport() override final;
    std::string get_name(const int& i) const override final ;
    int get_size() const override final ;
    void set_camel() override final ;
    void set_camel_is_fast() override final ;
    void set_centaur() override final ;
    void set_all_terrain_boots() override final ;
    double get_time (const int& i) const override final ;
};
#endif