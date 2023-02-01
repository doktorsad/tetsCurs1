#pragma once
#ifndef I_RACE_AIR_GROUND_H
#define I_RACE_AIR_GROUND_H
#include "Race.h"
class RaceOnGrondAndInAir;
class IRaceAirGround : public Race {
protected:
    virtual ~IRaceAirGround() = default;
    IRaceAirGround& operator= (const IRaceAirGround&) = delete;
    IRaceAirGround() = default;
public:
    virtual void bubble_sort_transport() = 0;
    virtual std::string get_name_air_vec(const int& i) const = 0;
    virtual std::string get_name_ground_vec(const int& i) const = 0;
    virtual std::string get_name_air_ground_vec(const int& i) const = 0;
    virtual std::string get_specilization_air_vec(const int& i) const = 0;
    virtual std::string get_specilization_ground_vec(const int& i) const = 0;
    virtual void set_magic_carpet() = 0;
    virtual void set_eagle() = 0;
    virtual void set_broomstick() = 0;
    virtual void set_camel() = 0;
    virtual void set_camel_is_fast() = 0;
    virtual void set_centaur() = 0;
    virtual void set_all_terrain_boots() = 0;
    virtual int get_size_air_vec() const = 0;
    virtual int get_size_ground_vec() const = 0;
    virtual int get_size_air_ground_vec() const = 0;
    virtual double get_time (const int& i) const  = 0;
    std::shared_ptr<RaceOnGrondAndInAir> creat_race_on_ground_in_air(const int& distance);
};
#endif