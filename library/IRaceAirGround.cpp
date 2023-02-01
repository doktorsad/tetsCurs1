#include "IRaceAirGround.h"

std::shared_ptr<RaceOnGrondAndInAir> creat_race_on_ground_in_air(const int& distance) {
    return std::make_shared<RaceOnGrondAndInAir>(distance);
}