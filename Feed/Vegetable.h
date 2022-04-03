#pragma once

#include "feed.h"

namespace animal_farm {
    struct Vegetable : virtual public feed {
        using feed::feed;

        FeedName getType() const override;

        std::unique_ptr<feed> getPointer() override;
    };
}