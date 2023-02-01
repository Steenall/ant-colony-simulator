#include "model/Colony.hpp"
#include "model/Map.hpp"
#include "model/Slaver.hpp"

Colony::Colony() {
    foodStock = 0;
    days = 0;
    queen = new Queen();
    queen->setCoordinate(Coordinate(WIDTH/2,HEIGHT/2));
    listAnt.push_back(queen);
    /*Worker * worker = new Worker();
    worker->setCoordinate(Coordinate(WIDTH/2+5,HEIGHT/2+5));
    listAnt.push_back((Ant*) worker);
    Slaver * slaver = new Slaver();
    slaver->setCoordinate(Coordinate(WIDTH/2-5,HEIGHT/2-5));
    listAnt.push_back((Ant*) slaver);
    Soldier * soldier = new Soldier();
    soldier->setCoordinate(Coordinate(WIDTH/2+5,HEIGHT/2-5));
    listAnt.push_back((Ant*) soldier);
    Scout * scout = new Scout();
    scout->setCoordinate(Coordinate(WIDTH/2-5,HEIGHT/2+5));
    listAnt.push_back((Ant*) scout);*/

}

void Colony::update() {

}

void Colony::addLarva(ColonyAnt ** larva) {
    for (int i = 0; i < NUMBER_OF_BABY_PER_ROUND; ++i) {
        listAnt.push_back((Ant*) larva[i]);
    }

}

Colony::~Colony() = default;

std::vector<Ant*> Colony::getAnts() {
    return listAnt;
}

unsigned Colony::getDay() {
    return days;
}

unsigned long Colony::getFoodQuantity() {
    return foodStock;
}

void Colony::addFood(unsigned food) {
    foodStock += food;
}

void Colony::incrementDay() {
    days++;
}
