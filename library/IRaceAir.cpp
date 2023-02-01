#include "IRaceAir.h"

std::shared_ptr<RaceInAir> creat_race_in_air(const int& distance) {
    return std::make_shared<RaceInAir>(distance);
}