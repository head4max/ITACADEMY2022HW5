#pragma once
#include <ostream>
#include <array>
#include <memory>

namespace animal_farm {
    const std::array<std::string, 3> FEED_NAME = {"Grain","Hay","Vegetable"};

    enum FeedName {
        GRAIN = 0, HAY = 1, VEGETABLE = 2, SIZE = 3
    };

    class feed {
        friend std::ostream& operator<<(std::ostream& outs, const feed& that);
    protected:
        unsigned qty_ = 0;

    public:
        //static const std::array<std::string, 3> FEED_NAME = {"Grain","Hay","Vegetable"};

        explicit feed(unsigned qty);

        unsigned getValue() const;

        bool operator==(const feed &that) const;

        bool operator==(unsigned numb) const;

        bool operator!=(unsigned numb) const;

        feed &operator=(unsigned numb);

        feed &operator-=(unsigned numb);

        feed &operator+=(unsigned numb);

        feed &operator-=(const feed &that);

        feed &operator--();

        virtual std::unique_ptr<feed> getPointer() = 0;

        bool consumeFeed(feed &that, unsigned limit);

        const std::string& getName() const;

        virtual FeedName getType() const = 0;
    };

    std::ostream& operator<<(std::ostream& outs, const animal_farm::feed& that);
}