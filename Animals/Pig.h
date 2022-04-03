#pragma once

#include "animals.h"
#include "../Feed/Vegetable.h"

namespace animal_farm {
    struct Pig : public animals {
        explicit Pig();

        const std::string &getVoice() const override;

        unsigned getLimit() const override;

        AnimalName getType() const override;
    };
}