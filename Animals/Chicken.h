#pragma once

#include "animals.h"
#include "../Feed/Grain.h"

namespace animal_farm {
    struct Chicken : public animals {
        Chicken();

        const std::string &getVoice() const override;

        unsigned getLimit() const override;

        AnimalName getType() const;
    };
}
