#include "IRaceGround.h"

std::shared_ptr<RaceOnGround> creat_race_on_ground(const int& distance) {
    return std::make_shared<RaceOnGround>(distance);
}