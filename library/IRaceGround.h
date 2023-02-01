#pragma once
#ifndef I_RACE_GROUND_H
#define I_RACE_GROUND_H
#include "Race.h"
class RaceOnGround;
class IRaceGround : public Race {
protected:
    virtual ~IRaceGround() = default;
    IRaceGround& operator= (const IRaceGround&) = delete;
    IRaceGround() = default;
public:
    virtual void bubble_sort_transport() = 0;
    virtual std::string get_name(const int& i) const = 0;
    virtual void set_camel() = 0;
    virtual void set_camel_is_fast() = 0;
    virtual void set_centaur() = 0;
    virtual void set_all_terrain_boots() = 0;
    virtual int get_size() const = 0;
    virtual double get_time (const int& i) const = 0;
    std::shared_ptr<RaceOnGround> creat_race_on_ground(const int& distance);
};
#endif