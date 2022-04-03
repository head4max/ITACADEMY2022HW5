#include "../Pig.h"

namespace af = animal_farm;

af::Pig::Pig() : animals(std::make_unique<Vegetable>(0)) {}

const std::string &af::Pig::getVoice() const { return ANIMAL_VOICE[AnimalName::PIG]; }

unsigned af::Pig::getLimit() const { return ANIMAL_LIMIT[AnimalName::PIG]; }

AnimalName af::Pig::getType() const { return AnimalName::PIG; }