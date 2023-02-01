#include "Broomstick.h"

 Broomstick::Broomstick(const int& distance) {
        this->speed = 20;
        this->name = "Broomstick";
        this->shortening_the_distance = 1 - ((distance / static_cast<double>(1000)) / 100);
        this->specialization = "air";
    }