#include "ITransportGround.h"

std::shared_ptr<Camel> ITransportGround::creat_camel() {
        return std::make_shared<Camel>();
}

std::shared_ptr<CamelIsFast> ITransportGround::creat_camel_is_fast() {
        return std::make_shared<CamelIsFast>();
}

std::shared_ptr<Centaur> ITransportGround::creat_centaur() {
        return std::make_shared<Centaur>();
}

std::shared_ptr<AllTerrainBoots> ITransportGround::creat_all_terrain_boots() {
        return std::make_shared<AllTerrainBoots>();
}