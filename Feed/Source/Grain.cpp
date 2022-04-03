#include "../Grain.h"
#include <iostream>

namespace af = animal_farm;

af::FeedName af::Grain::getType() const { return FeedName::GRAIN; }

std::unique_ptr<af::feed> af::Grain::getPointer() {
    return std::make_unique<Grain>(qty_);
}
