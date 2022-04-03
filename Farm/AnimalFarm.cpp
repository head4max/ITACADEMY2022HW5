#include "AnimalFarm.h"

namespace af = animal_farm;

std::ostream &af::operator<<(std::ostream &outs, const af::AnimalFarm &that){

    if(that.getAnimalCount()>0) {
        outs << "Animals:" << std::endl;
        for (auto &itt_anim: that.corral4animals)
            outs << *itt_anim;
    }else
        outs << "No animals in the farm" << std::endl;

    if(that.getFeedsCount()>0) {
        outs << std::endl << "Feeds:" << std::endl;
        for (auto &itt_feed: that.storehouse4feed)
            outs << *itt_feed;
    }else
        outs << "No feeds in the farm" << std::endl;

    return outs;
}

const af::animals &animal_farm::AnimalFarm::getAnimal(std::size_t i) const {
    return *corral4animals[i];
}

std::size_t af::AnimalFarm::getAnimalCount() const{return corral4animals.size();}

const std::unique_ptr<af::feed>& animal_farm::AnimalFarm::getFeed(std::size_t i) const {
    return storehouse4feed[i];
}

std::size_t af::AnimalFarm::getFeedsCount() const{return storehouse4feed.size();}

void af::AnimalFarm::addFeed(std::vector<FeedName> &&group_feed, std::vector<unsigned int> &&count_feed) {
    for (unsigned i = 0; i < group_feed.size(); ++i) {
        if (i < count_feed.size() ? count_feed[i] > 0 : false) {
            bool isConsumed = false;

            for (auto &itt: storehouse4feed)
                if (group_feed[i] == itt->getType()) {
                    *itt += count_feed[i];
                    isConsumed = true;
                    break;
                }

            //можно ли сохранить map состоящую из предикатов (ссылок на конструкторы) и вызывать их здесь по перечислению?
            if (!isConsumed)
                switch (group_feed[i]) {
                    case FeedName::HAY:
                        storehouse4feed.push_back(std::make_unique<Hay>(count_feed[i]));
                        break;
                    case FeedName::GRAIN:
                        storehouse4feed.push_back(std::make_unique<Grain>(count_feed[i]));
                        break;
                    case FeedName::VEGETABLE:
                        storehouse4feed.push_back(std::make_unique<Vegetable>(count_feed[i]));
                }
        }
    }
}

void af::AnimalFarm::feedAnimals() {
    for(auto& itt:corral4animals){
        if(itt->isHungry()){
            std::string animal_voice;
            bool isHungry = true;

            //std::cout << *itt;
            //std::size_t j = 0;
            //bool isDelete = false;
/*
            //for(auto& itt_feed:storehouse4feed){
            for(std::size_t i = 0; i < storehouse4feed.size(); ++i){
                if(itt->eat(*storehouse4feed[i])){
                    //std::cout << itt->isHungry()?itt->getVoice():itt->getUnsatisfiedVoice();
                    isHungry = itt->isHungry();
                    if(*storehouse4feed[i] == 0){
                        //storehouse4feed.erase();
                        isDelete = true;
                        j = i;
                    }
                        //storehouse4feed.erase(storehouse4feed.begin()+i);
                    break;
                }
            }
*/
            auto itt1 = storehouse4feed.begin();
            for(;itt1 != storehouse4feed.end();++itt1){
                if(itt->eat(*itt1->get()/**itt_feed*/)){
                    //if(itt1->get()->getValue() == 0)
                    //    storehouse4feed.erase(itt1);

                    isHungry = itt->isHungry();
                    break;
                }
            }
            //не получается удалить поинтер из вектора
/*
            for(auto ittf = storehouse4feed.begin();ittf!=storehouse4feed.end();++ittf)
                if(ittf->get()->getValue() == 0)
                    storehouse4feed.erase(ittf);
*/
            //if(isDelete)
            //    storehouse4feed.erase(storehouse4feed.begin()+j);
            //std::cout << storehouse4feed.size() << std::endl;

            std::cout << *itt;
            std::cout << (isHungry?itt->getUnsatisfiedVoice():itt->getVoice()) << std::endl << std::endl;
        }
    }
}

void af::AnimalFarm::AddAnimals(std::vector<AnimalName> &&group_animals) {
    for (auto itt: group_animals)
        switch (itt) {
            case AnimalName::PIG:
                corral4animals.push_back(std::make_unique<Pig>());
            case AnimalName::COW:
                corral4animals.push_back(std::make_unique<Cow>());
            case AnimalName::CHICKEN:
                corral4animals.push_back(std::make_unique<Chicken>());
        }
}

void af::AnimalFarm::addFeed(std::vector<std::unique_ptr<feed>> &&group_feed) {
    for (unsigned i = 0; i < group_feed.size(); ++i) {
            bool isConsumed = false;

            for (auto &itt: storehouse4feed)
                if (*group_feed[i] == *itt) {
                    *itt += group_feed[i]->getValue();
                    isConsumed = true;
                    break;
                }

        if (!isConsumed)
            storehouse4feed.push_back(std::move(group_feed[i]));
        }
}
