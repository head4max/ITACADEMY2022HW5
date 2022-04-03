#pragma once

#include "animals.h"
#include "../Feed/Hay.h"

namespace animal_farm {
    struct Cow : public animals {
    public:
        Cow();

        const std::string &getVoice() const override;

        unsigned getLimit() const override;

        AnimalName getType() const override;
    };
}