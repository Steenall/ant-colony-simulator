#include <iostream>
#include "model/Ant.hpp"
#include "model/Direction.hpp"

//Init static variable
unsigned long Ant::idCount = 0;

Ant::Ant() {
    coordinate = Coordinate(0,0);
    countChunks = 0;
    id = idCount++;
    pathing.clear();
}

Ant::~Ant() {
    pathing.clear();
}

void Ant::setCoordinate(Coordinate coordinate) {
    this->coordinate = coordinate;
}

Coordinate Ant::getCoordinate() {
    return coordinate;
}

Action Ant::update(Map map) {
    return SEARCH_FOR_FOOD;
}

void Ant::moveBackward(Map * map) {
    if(countChunks > 0) {
        map->removeAnt(coordinate.x, coordinate.y, this);
        countChunks--;
        Direction direction = pathing[countChunks];
        coordinate = getCoordinateWithDirection(coordinate, getOppositeDirection(direction));
        map->addAnt(coordinate.x, coordinate.y, this);
    }
}

void Ant::moveTo(Map * map, Direction direction) {
    map->removeAnt(coordinate.x, coordinate.y, this);
    Coordinate newCoordinate = getCoordinateWithDirection(coordinate, direction);
    //Check if pathing contains the newCoordinate
    int idx = -1;
    Coordinate currentCoordinate = homeCoordinate;
    for (int i=0; i<countChunks; i++) {
        Direction pathingDirection = pathing[i];
        currentCoordinate = getCoordinateWithDirection(currentCoordinate, pathingDirection);
        if(currentCoordinate.x == newCoordinate.x && currentCoordinate.y == newCoordinate.y) {
            idx = i;
            break;
        }
    }
    if(idx!=-1) {
        pathing.erase(pathing.begin()+idx+1, pathing.end());
        countChunks = idx;
    } else {
        pathing.push_back(direction);
        countChunks++;
    }
    //std::cout << "Je me déplace vers la direction : " << direction << "de [" << coordinate.x << "," << coordinate.y << "] vers [" << newCoordinate.x << "," << newCoordinate.y << ']' << std::endl;
    coordinate = newCoordinate;
    map->addAnt(coordinate.x, coordinate.y, this);

}

void Ant::setHomeCoordinate(Coordinate coordinate) {
    homeCoordinate = coordinate;
}

bool Ant::operator==(const Ant &other) const {
    return id == other.id;
}

bool Ant::isAtHome() {
    return homeCoordinate == coordinate;
}
