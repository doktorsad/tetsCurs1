#pragma once
#ifndef I_RACE_AIR_H
#define I_RACE_AIR_H
#include "Race.h"
class RaceInAir;
class IRaceAir : public Race {
protected:
    virtual ~IRaceAir() = default;
    IRaceAir& operator= (const IRaceAir&) = delete;
    IRaceAir() = default;
public:
    virtual void bubble_sort_transport() = 0;
    virtual std::string get_name(const int& i) const = 0;
    virtual void set_magic_carpet() = 0;
    virtual void set_eagle() = 0;
    virtual void set_broomstick() = 0;
    virtual int get_size() const = 0;
    virtual double get_time(const int& i) const = 0;
    std::shared_ptr<RaceInAir> creat_race_in_air(const int& distance);
};
#endif