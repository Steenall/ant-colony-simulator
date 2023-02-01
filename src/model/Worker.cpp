#include <iostream>
#include "model/Worker.hpp"

Worker::Worker() {
    carringFood = false;
    dayBeforeMajority = 15;
}

Action Worker::update(Map map) {
    if(isMinor()){
        dayBeforeMajority -=1;
        return Action::NOTHING;
    }
    else{
        if(!isCarringFood()){
            return Action::SEARCH_FOR_FOOD;
         }
        else{
            return Action::GO_BACK_TO_COLONY_WITH_FOOD;
        }
    }


}
bool Worker::isMinor() {
    return dayBeforeMajority > 0;
}

bool Worker::isCarringFood() {
    return carringFood;
}

void Worker::setCarringFood(bool carringFood) {
    this->carringFood = carringFood;
}

Worker::~Worker() {};