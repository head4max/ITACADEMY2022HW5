#include "../Vegetable.h"
#include <iostream>

namespace af = animal_farm;

af::FeedName af::Vegetable::getType() const { return FeedName::VEGETABLE; }

std::unique_ptr<af::feed> af::Vegetable::getPointer() {
    return std::make_unique<Vegetable>(qty_);
}
