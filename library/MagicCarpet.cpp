#include "MagicCarpet.h"
MagicCarpet::MagicCarpet(const int& distance) {
        this->speed = 10;
        this->name = "Magic Carpet";
        this->specialization = "air";
        if (distance < 1000)
            this->shortening_the_distance = 1;
        else if (distance < 5000 && distance >= 1000)
            this->shortening_the_distance = 0.97;
        else if (distance < 10000 && distance >= 5000)
            this->shortening_the_distance = 0.9;
        else if (distance >= 10000)
            this->shortening_the_distance = 0.95;
}