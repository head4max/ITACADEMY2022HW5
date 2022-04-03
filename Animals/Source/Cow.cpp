#include "../Cow.h"

namespace af = animal_farm;

af::Cow::Cow() : animals(std::make_unique<Hay>(0)) {}

const std::string &af::Cow::getVoice() const { return ANIMAL_VOICE[AnimalName::COW]; }

unsigned af::Cow::getLimit() const { return ANIMAL_LIMIT[AnimalName::COW]; }

AnimalName af::Cow::getType() const { return AnimalName::COW; }