#pragma once
#ifndef RACE_H
#define RACE_H
#include "MagicCarpet.h"
#include "Eagle.h"
#include "Broomstick.h"
#include "Camel.h"
#include "CamelIsFast.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include <vector>
#include <algorithm>
class Race {
protected:
    int distance;
    Race() = default;
    virtual ~Race() = default;
};
#endif
