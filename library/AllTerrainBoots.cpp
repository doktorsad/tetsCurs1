#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots() {
    this->speed = 6;
    this->time_befor_bedtime = 60;
    this->sleep_time = 10;
    this->name = "All Terrain Boots";
    this->specialization = "ground";
}
double AllTerrainBoots::get_update_sleep() const { return 5; }