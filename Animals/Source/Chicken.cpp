#include "../Chicken.h"

namespace af = animal_farm;

af::Chicken::Chicken() : animals(std::make_unique<Grain>(0)) {}

const std::string &af::Chicken::getVoice() const{ return ANIMAL_VOICE[AnimalName::CHICKEN]; }

unsigned af::Chicken::getLimit() const{ return ANIMAL_LIMIT[AnimalName::CHICKEN]; }

AnimalName af::Chicken::getType() const{return AnimalName::CHICKEN;}