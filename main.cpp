#include "Animals/animals.h"
#include "Feed/feed.h"
#include <vector>
#include "Farm/AnimalFarm.h"

int main() {

    /*
     * //проверка удаления из вектора поинтеров
    std::vector<std::unique_ptr<int>> vec1;// = {8,0,8};
    vec1.push_back(std::make_unique<int>(7));
    vec1.push_back(std::make_unique<int>(0));
    vec1.push_back(std::make_unique<int>(3));

    auto itt11 = vec1.begin();
    for(auto itt = vec1.begin();itt != vec1.end();++itt)
        if(*itt->get() == 0)
            itt11 = itt;
    vec1.erase(itt11);
    std::cout << vec1.size() << std::endl;

    for(auto& itt2:vec1)
        std::cout << *itt2 << std::endl;
     */

    animal_farm::AnimalFarm animf = animal_farm::AnimalFarm();

    //animf.AddAnimals({AnimalName::PIG,AnimalName::COW,AnimalName::CHICKEN});

    //добавление животных через вектор
    //std::vector<AnimalName> animals_tmp = {AnimalName::PIG,AnimalName::COW,AnimalName::CHICKEN};
    //animf.AddAnimals(std::move(animals_tmp));

    //через R-value
    animf.AddAnimals({AnimalName::PIG,AnimalName::COW,AnimalName::CHICKEN, AnimalName::COW, AnimalName::CHICKEN});

    //добавление через вектор
    std::vector<animal_farm::FeedName> feeds = {animal_farm::FeedName::HAY,animal_farm::FeedName::GRAIN,animal_farm::FeedName::VEGETABLE,animal_farm::FeedName::HAY};
    std::vector<unsigned > counts4feeds = {40,30,20,6};
    animf.addFeed(std::move(feeds),std::move(counts4feeds));

    //animal_farm::Hay(40).getPointer()
    //std::vector<animal_farm::feed> = {animal_farm::Hay(40).getPointer(),animal_farm::Grain(30).getPointer(),animal_farm::Vegetable(20).getPointer(),animal_farm::Hay(6).getPointer()};
    //animf.addFeed({animal_farm::Hay(40).getPointer(),animal_farm::Grain(30).getPointer(),animal_farm::Vegetable(20).getPointer(),animal_farm::Hay(6).getPointer()});

    std::cout << animf;

    animf.feedAnimals();
    std::cout << animf;

    feeds = {animal_farm::FeedName::HAY,animal_farm::FeedName::GRAIN,animal_farm::FeedName::VEGETABLE,animal_farm::FeedName::HAY};
    counts4feeds = {40,30,20,6};
    animf.addFeed(std::move(feeds),std::move(counts4feeds));
    animf.feedAnimals();
    std::cout << animf;
    return 0;
}
