#include "../feed.h"
#include <iostream>

namespace af = animal_farm;

af::feed::feed(unsigned qty) : qty_(qty) {}

af::feed &af::feed::operator-=(const feed &that) {
    if (*this == that)
        *this -= that.qty_;
    return *this;
}

bool af::feed::operator==(unsigned int numb) const {return qty_ == numb;}

bool af::feed::operator!=(unsigned numb) const{return (qty_ != numb);}

bool animal_farm::feed::consumeFeed(feed &that, unsigned int limit) {
    if (*this == that) {
        unsigned diff = (qty_ + that.qty_ < limit ? that.qty_ : (limit - qty_));

        if (diff == 0)
            return false;
        else {
            qty_ += diff;
            that.qty_ -= diff;
        }
        return true;
    }

    return false;
}

bool af::feed::operator==(const feed &that) const { return getType() == that.getType(); }

af::feed &af::feed::operator=(unsigned numb) {
    qty_ = numb;
    return *this;
}

af::feed &af::feed::operator-=(unsigned numb) {
    qty_ -= numb;
    return *this;
}

af::feed &af::feed::operator--() {
    --qty_;
    return *this;
}

af::feed &af::feed::operator+=(unsigned int numb) {
    qty_ += numb;
    return *this;
}

unsigned af::feed::getValue() const {
    return qty_;
}

std::ostream &af::operator<<(std::ostream &outs, const af::feed &that) {
    outs << that.getName() << ": " << that.getValue() << std::endl;
    return outs;
}

const std::string &af::feed::getName() const {
    return FEED_NAME[getType()];
}

