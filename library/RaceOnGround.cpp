#include "RaceOnGround.h"

RaceOnGround::RaceOnGround(const int& distance) { this->distance = distance; }
void RaceOnGround::bubble_sort_transport()  {
    for (size_t idx_i = 0; idx_i + 1 < transports.size(); ++idx_i) {
        for (size_t idx_j = 0; idx_j + 1 < transports.size() - idx_i; ++idx_j) {
            if (get_time(idx_j + 1) < get_time(idx_j)) {
                std::swap(transports[idx_j], transports[idx_j + 1]);
            }
        }
    }
}
    
std::string RaceOnGround::get_name(const int& i) const { return transports[i]->get_name(); }

int RaceOnGround::get_size() const {return transports.size();}

void RaceOnGround::set_camel() {
    transports.push_back(ITransportGround::creat_camel());
}

void RaceOnGround::set_camel_is_fast() {
    transports.push_back(ITransportGround::creat_camel_is_fast());
}

void RaceOnGround::set_centaur() {
    transports.push_back(ITransportGround::creat_centaur());
}

void RaceOnGround::set_all_terrain_boots() {
    transports.push_back(ITransportGround::creat_all_terrain_boots());
}

double RaceOnGround::get_time (const int& i) const  {
    double time = static_cast<double>(this->distance) / static_cast<double>(transports[i]->get_speed());
    int cycle = static_cast<int>(time) / transports[i]->get_time_before_bedtime();
    if (transports[i]->get_name() == "Camel" || transports[i]->get_name() == "All Terrain Boots") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                if (k == 1) {
                    time += transports[i]->get_this_sleep_time();
                    continue;
                }
                time += transports[i]->get_update_sleep();
            }
        }
        return time;
    }
    else if (transports[i]->get_name() == "Camel Fast") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                if (k == 0) {
                    time += transports[i]->get_this_sleep_time();
                    continue;
                }
                if (k == 1) {
                    time += transports[i]->get_update_sleep();
                    continue;
                }
                time += transports[i]->get_update_sleep_second();
                }
            }
            return time;
        }
        else if (transports[i]->get_name() == "Centaur") {
            if (cycle >= 1) {
                for (int k = 0; k < cycle; ++k) {
                    time += transports[i]->get_this_sleep_time();
                }
            }
            return time;
        }
        return 0;
    }