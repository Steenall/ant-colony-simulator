#include <iostream>
#include "model/Scout.hpp"

Scout::Scout() {
    dayBeforeMajority = 2;
}
Action Scout::update(Map map){
    if(isMinor()){
        dayBeforeMajority -=1;
        //std::cout << "Je ne fais rien" << std::endl;
        return Action::NOTHING;
    }
    else{
        //std::cout << "J'explore" << std::endl;
        return  Action::EXPLORE;

    }
}
bool Scout::isMinor() {
    return dayBeforeMajority > 0;
}

Scout::~Scout() = default;