#pragma once
#include "../Feed/feed.h"
#include <iostream>
#include <array>
#include <memory>

//const std::string HUNGRY_VOICE = ("PpPpPp!!!");
//const std::array<std::string, 3> ANIMAL_NAME{"Cow","Chicken","Pig"};
//const std::array<std::string, 3> ANIMAL_VOICE{"Muu!!!","Ko-Ko-Ko!!!","Hruu!!!"};
//const std::array<unsigned , 3> ANIMAL_LIMIT{35,10,20};
enum AnimalName{COW = 0,CHICKEN = 1,PIG = 2};

namespace animal_farm {

    class animals {
        friend std::ostream& operator<<(std::ostream& outs, const animals& anim);
    protected:
        static const std::string HUNGRY_VOICE;
        static const std::array<std::string, 3> ANIMAL_NAME;
        static const std::array<std::string, 3> ANIMAL_VOICE;
        static const std::array<unsigned , 3> ANIMAL_LIMIT;
        std::unique_ptr<feed> feed_;
    public:
        explicit animals(std::unique_ptr<feed> f);

        static const std::string &getUnsatisfiedVoice();
        bool isHungry();
        unsigned getSatiety() const;
        //bool eat(std::unique_ptr<feed>& some_feed);
        bool eat(feed& some_feed);
        virtual const std::string &getVoice() const = 0;
        virtual unsigned getLimit() const = 0;
        virtual AnimalName getType() const = 0;
        const std::string& getName() const;
    };

    std::ostream& operator<<(std::ostream& outs, const animals& anim);
}