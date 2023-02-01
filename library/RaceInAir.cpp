#include "RaceInAir.h"
RaceInAir::RaceInAir(const int& distance) { this->distance = distance;}
void RaceInAir::bubble_sort_transport() {
    std::sort(this->transports.begin(), transports.end(), [](const auto& rhs, const auto& lhs) {
        return rhs->get_shortening_the_distatnce() / rhs->get_speed() <
            lhs->get_shortening_the_distatnce() / lhs->get_speed();
        });
    }
    std::string RaceInAir::get_name(const int& i) const { return transports[i]->get_name(); }
    int RaceInAir::get_size() const {return transports.size();}
    void RaceInAir::set_magic_carpet() {
        transports.push_back(ITransportAir::creat_magic_carpet(this->distance));
    }
    void RaceInAir::set_eagle() {
        transports.push_back(ITransportAir::creat_eagle());
    }
    void RaceInAir::set_broomstick() {
        transports.push_back(ITransportAir::creat_broomstick(this->distance));
    }
    double RaceInAir::get_time(const int& i) const {
        return ((distance * transports[i]->get_shortening_the_distatnce()) / transports[i]->get_speed());
    }