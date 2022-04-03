#include "../Hay.h"
#include <iostream>

namespace af = animal_farm;

af::FeedName af::Hay::getType() const { return FeedName::HAY; }

std::unique_ptr<af::feed> af::Hay::getPointer() {
    return std::make_unique<Hay>(qty_);
}
