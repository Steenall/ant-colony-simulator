#include "model/Chunk.hpp"
#include <iostream>
#include <vector>

using namespace std;

Chunk::Chunk(TypeOfChunk type, unsigned int foodQuantity) {
    typeOfChunk = type;
    this->foodQuantity = foodQuantity;
    explored = false;
    pheromomeQuantity = 0;

}

/*void Chunk::setBorder(Chunk * chunk, Direction direction) {
    borderChucks[direction] = chunk;
}*/

void Chunk::setTypeOfChunk(TypeOfChunk type) {
    typeOfChunk = type;
}

void Chunk::setFoodQuantity(unsigned newFoodQuantity) {
    foodQuantity = newFoodQuantity;
}

unsigned Chunk::getFoodQuantity() {
    return foodQuantity;
}

TypeOfChunk Chunk::getTypeOfChunk() {
    return typeOfChunk;
}

bool Chunk::isExplored() {
    return explored;
}


Chunk::~Chunk() {
    //delete[] borderChucks;
}

void Chunk::setPheromone(unsigned int pheromone) {
    pheromomeQuantity = pheromone;
}

unsigned int Chunk::getPheromone() {
    return pheromomeQuantity;
}

void Chunk::setExplored(bool explored) {
    this->explored = explored;
}

void Chunk::addAnt(Ant *ant) {
    listAnt.push_back(ant);
}

void Chunk::setAnts(std::vector<Ant *> ants) {
    listAnt = ants;
}

void Chunk::removeAnt(Ant *ant) {
    //Remove ant from list
    for (int i = 0; i < listAnt.size(); ++i) {
        if(listAnt[i] == ant) {
            listAnt.erase(listAnt.begin() + i);
        }
    }
}

std::vector<Ant *> Chunk::getAnts() {
    return listAnt;
}
