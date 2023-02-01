#include "RaceOnGroundAndInAir.h"

RaceOnGrondAndInAir::RaceOnGrondAndInAir(const int& distance) {
        this->distance = distance; 
}

void RaceOnGrondAndInAir::bubble_sort_transport() {
    sort_transport_air();
    sort_transport_ground();
    int idx_i = 0;
    int idx_k = 0;
    while (true) {
        if (get_time_air(idx_i) > get_time_ground(idx_k)) {
            transport_all.push_back(transports_second[idx_k]);
            time.push_back(get_time_ground(idx_k));
            ++idx_k;
        }else if (get_time_air(idx_i) < get_time_ground(idx_k)) {
            transport_all.push_back(transports_first[idx_i]);
            time.push_back(get_time_air(idx_i));
            ++idx_i;
        } else if(get_time_air(idx_i) == get_time_ground(idx_k)){
            transport_all.push_back(transports_first[idx_i]);
            transport_all.push_back(transports_second[idx_k]);
            time.push_back(get_time_air(idx_i));
            time.push_back(get_time_ground(idx_k));
            ++idx_k;
            ++idx_i;
        }
        if (idx_i == transports_first.size()) {
            for (int i = idx_k; i < transports_second.size(); ++i) {
                transport_all.push_back(transports_second[i]);
                time.push_back(get_time_ground(i));
            }
            break;
        }
        if (idx_k == transports_second.size()) {
            for (int i = idx_i; i < transports_first.size(); ++i) {
                transport_all.push_back(transports_first[i]);
                time.push_back(get_time_air(i));
            }
            break;
        }
    }
}

void RaceOnGrondAndInAir::set_magic_carpet() {
    transports_first.push_back(ITransportAir::creat_magic_carpet(this->distance));
}

void RaceOnGrondAndInAir::set_eagle()  {
    transports_first.push_back(ITransportAir::creat_eagle());
}

void RaceOnGrondAndInAir::set_broomstick() {
    transports_first.push_back(ITransportAir::creat_broomstick(this->distance));
}

void RaceOnGrondAndInAir::set_camel() {
    transports_second.push_back(ITransportGround::creat_camel());
}

void RaceOnGrondAndInAir::set_camel_is_fast() {
    transports_second.push_back(ITransportGround::creat_camel_is_fast());
}

void RaceOnGrondAndInAir::set_centaur() {
    transports_second.push_back(ITransportGround::creat_centaur());
}

void RaceOnGrondAndInAir::set_all_terrain_boots() {
    transports_second.push_back(ITransportGround::creat_all_terrain_boots());
}

std::string RaceOnGrondAndInAir::get_name_air_vec(const int& i) const {
    return transports_first[i]->get_name();
}

std::string RaceOnGrondAndInAir::get_name_ground_vec(const int& i) const {
    return transports_second[i]->get_name();
}

std::string RaceOnGrondAndInAir::get_name_air_ground_vec(const int& i) const {
    return transport_all[i]->get_name();
}

std::string RaceOnGrondAndInAir::get_specilization_air_vec(const int &i) const {
    return transports_first[i]->get_specialization();
}

std::string RaceOnGrondAndInAir::get_specilization_ground_vec(const int& i) const {
    return transports_second[i]->get_specialization();
}

int RaceOnGrondAndInAir::get_size_air_vec() const {return transports_first.size();}

int RaceOnGrondAndInAir::get_size_ground_vec() const {return transports_second.size();}

int RaceOnGrondAndInAir::get_size_air_ground_vec() const {return transport_all.size();}

double RaceOnGrondAndInAir::get_time(const int &i)const {return this->time[i];}

void RaceOnGrondAndInAir::sort_transport_air() {
    for (size_t idx_i = 0; idx_i + 1 < transports_first.size(); ++idx_i) {
        for (size_t idx_j = 0; idx_j + 1 < transports_first.size() - idx_i; ++idx_j) {
            if (get_time_air(idx_j + 1) < get_time_air(idx_j)) {
                std::swap(transports_first[idx_j], transports_first[idx_j + 1]);
            }
        }
    }
}

void RaceOnGrondAndInAir::sort_transport_ground() {
    for (size_t idx_i = 0; idx_i + 1 < transports_second.size(); ++idx_i) {
        for (size_t idx_j = 0; idx_j + 1 < transports_second.size() - idx_i; ++idx_j) {
            if (get_time_ground(idx_j + 1) < get_time_ground(idx_j)) {
                std::swap(transports_second[idx_j], transports_second[idx_j + 1]);
            }
        }
    }
}

double RaceOnGrondAndInAir::get_time_ground(const int& i) {
    double time = static_cast<double>(this->distance) / static_cast<double>(transports_second[i]->get_speed());
    int cycle = static_cast<int>(time) / transports_second[i]->get_time_before_bedtime();
    if (transports_second[i]->get_name() == "Camel" || transports_second[i]->get_name() == "All Terrain Boots") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                if (k == 1) {
                    time += transports_second[i]->get_this_sleep_time();
                    continue;
                }
                time += transports_second[i]->get_update_sleep();
            }
        }
        return time;
    }
    else if (transports_second[i]->get_name() == "Camel Fast") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                if (k == 1) {
                    time += transports_second[i]->get_this_sleep_time();
                    continue;
                }
                if (k == 2) {
                    time += transports_second[i]->get_update_sleep();
                    continue;
                }
                time += transports_second[i]->get_update_sleep_second();
            }
        }
        return time;
    }
    else if (transports_second[i]->get_name() == "Centaur") {
        if (cycle >= 1) {
            for (int k = 0; k < cycle; ++k) {
                time += transports_second[i]->get_this_sleep_time();
            }
        }
        return time;
    }
    return 0;
}

double RaceOnGrondAndInAir::get_time_air(const int& i) {
    return ((distance * transports_first[i]->get_shortening_the_distatnce()) / transports_first[i]->get_speed());
}
