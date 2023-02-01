#pragma once
#ifndef RACE_ON_GROUND_AND_IN_AIR_H
#define RACE_ON_GROUND_AND_IN_AIR_H
#include "IRaceAirGround.h"
class RaceOnGrondAndInAir : public IRaceAirGround {
protected:
    std::vector <std::shared_ptr<ITransportAir > > transports_first;
    std::vector <std::shared_ptr<ITransportGround > > transports_second;
    std::vector <std::shared_ptr<TransportVehicle > > transport_all;
    std::vector <double> time;
public:
    RaceOnGrondAndInAir() = delete;
    RaceOnGrondAndInAir(const int& distance);

    void bubble_sort_transport() override final;
    void set_magic_carpet() override final ;
    void set_eagle() override final ;
    void set_broomstick() override final ;
    void set_camel() override final ;
    void set_camel_is_fast() override final ;
    void set_centaur() override final ;
    void set_all_terrain_boots() override final ;
    std::string get_name_air_vec(const int& i) const override final ;
    std::string get_name_ground_vec(const int& i) const override final ;; 
    std::string get_name_air_ground_vec(const int& i) const override final ;
    std::string get_specilization_air_vec(const int &i) const override final ;
    std::string get_specilization_ground_vec(const int& i) const override final ;
    int get_size_air_vec() const override final ;
    int get_size_ground_vec() const override final ;
    int get_size_air_ground_vec() const override final ;
    double get_time(const int &i)const override final ;
protected:
    void sort_transport_air() ;

    void sort_transport_ground() ;

    double get_time_ground(const int& i) ;

    double get_time_air(const int& i) ;
};

#endif