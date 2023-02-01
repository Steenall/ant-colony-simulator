#include <chrono>
#include <random>
#include "model/Queen.hpp"
#include "model/Worker.hpp"
#include "model/Soldier.hpp"
#include "model/Scout.hpp"

Queen::Queen() {
    isAgressed = false;
    currentAge = 0;
    coordinate = Coordinate(WIDTH/2,HEIGHT/2);
    currentChilds = new ColonyAnt *[2];
    currentChilds[0] = new Scout();
    currentChilds[0]->setHomeCoordinate(coordinate);
    currentChilds[0]->setCoordinate(coordinate);
    currentChilds[1] = new Scout();
    currentChilds[1]->setHomeCoordinate(coordinate);
    currentChilds[1]->setCoordinate(coordinate);
}

Action Queen::update(Map map) {
    if(!isAgressed) {
        return Action::BORN;
    }else {
        isAgressed = false;
        return Action::NOTHING;
    }
}

ColonyAnt ** Queen::getChilds() {
    return currentChilds;
}

void Queen::born() {
    currentChilds = Queen::createLarva(coordinate);
}

ColonyAnt ** Queen::createLarva(Coordinate coordinate) {
    ColonyAnt ** ants = new ColonyAnt *[2];
    std::random_device rd;
    long seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);
    std::uniform_int_distribution<unsigned> dist(0, 100);
    for(int i = 0; i < 2; i++) {
        unsigned prob = dist(mt);
        if(prob <= 80) {
            Worker * w = new Worker();
            ants[i] = (ColonyAnt*) w;
        }else if(prob <= 95) {
            Soldier * s = new Soldier();
            ants[i] = (ColonyAnt*) s;
        }else {
            Scout * s = new Scout();
            ants[i] = (ColonyAnt*) s;
        }
        ants[i]->setCoordinate(coordinate);
        ants[i]->setHomeCoordinate(coordinate);
    }
    return ants;
}

Queen::~Queen() {
    delete currentChilds;
}
