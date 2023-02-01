#include "ITransportAir.h"

std::shared_ptr<MagicCarpet> ITransportAir::creat_magic_carpet(const int& distance) {
    return std::make_shared<MagicCarpet>(distance);
}
std::shared_ptr<Eagle> ITransportAir::creat_eagle() {
        return std::make_shared<Eagle>();
}
std::shared_ptr<Broomstick> ITransportAir::creat_broomstick(const int& distance) {
        return std::make_shared<Broomstick>(distance);
}
