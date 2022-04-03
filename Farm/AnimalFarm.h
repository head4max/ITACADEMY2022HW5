#pragma once

#include "../Feed/feed.h"
#include "../Feed/Hay.h"
#include "../Feed/Grain.h"
#include "../Feed/Vegetable.h"
#include "../Animals/animals.h"
#include "../Animals/Cow.h"
#include "../Animals/Chicken.h"
#include "../Animals/Pig.h"
#include <vector>

namespace animal_farm {
    class AnimalFarm {
        friend std::ostream& operator<<(std::ostream& outs, const AnimalFarm& that);
    private:
        std::vector<std::unique_ptr<animals>> corral4animals;
        std::vector<std::unique_ptr<feed>> storehouse4feed;

    public:
        AnimalFarm() { corral4animals.reserve(FeedName::SIZE); }

        const animals& getAnimal(std::size_t i) const;

        std::size_t getAnimalCount() const;

        const std::unique_ptr<feed>& getFeed(std::size_t i) const;

        std::size_t getFeedsCount() const;

        void AddAnimals(std::vector<AnimalName>&& group_animals);

        void addFeed(std::vector<FeedName> &&group_feed, std::vector<unsigned> &&count_feed);

        void addFeed(std::vector<std::unique_ptr<feed>>&& group_feed);

        void feedAnimals();
    };

    std::ostream& operator<<(std::ostream& outs, const AnimalFarm& that);
}