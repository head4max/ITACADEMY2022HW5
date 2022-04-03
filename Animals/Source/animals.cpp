#include "../animals.h"

namespace af = animal_farm;

const std::string af::animals::HUNGRY_VOICE = ("PpPpPp!!!");
const std::array<std::string, 3> af::animals::ANIMAL_NAME = {"Cow","Chicken","Pig"};
const std::array<std::string, 3> af::animals::ANIMAL_VOICE = {"Muu!!!","Ko-Ko-Ko!!!","Hruu!!!"};
const std::array<unsigned , 3> af::animals::ANIMAL_LIMIT = {35,10,20};

af::animals::animals(std::unique_ptr<feed> f) : feed_(std::move(f)) {}

const std::string &af::animals::getUnsatisfiedVoice() { return HUNGRY_VOICE; }

bool af::animals::eat(animal_farm::feed& some_feed) {
    return (*feed_ == some_feed) ? (feed_->consumeFeed(some_feed, getLimit())) : false;
}

bool af::animals::isHungry() { return (*feed_ != getLimit()); }

std::ostream &af::operator<<(std::ostream &outs, const animals &anim) {
    outs << anim.getName() << ": " << anim.getSatiety() << "/" << anim.getLimit() << std::endl;

    return outs;
}

unsigned af::animals::getSatiety() const{
    return feed_->getValue();
}

const std::string &af::animals::getName() const {return af::animals::ANIMAL_NAME[getType()];}
