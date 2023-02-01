#include <list>
#include <random>
#include <chrono>
#include <iostream>
#include "model/Direction.hpp"
#include "model/Game.hpp"
#include "model/Colony.hpp"
#include "model/Slaver.hpp"

Map *Game::getMap() {
    return map;
}

Game::Game(Map *map, Colony *colony) {
    this->map = map;
    this->colony = colony;
    exporter = new ColonyEvolutionExporter(DEFAULT_FILE_NAME_EXPORT);
    isRunning = true;

}

void Game::updateAllAnts() {
    std::cout << "Jour "<< colony->getDay()  << std::endl;

    for (Ant *ant : colony->getAnts()) {
        Action antAction =  ant->update(*map);
        Coordinate coordinate = ant->getCoordinate();
        if(!updateAnt(map, ant, antAction, coordinate)) {
            break;
        }
    }
    exporter->update(colony);
    colony->incrementDay();
}

bool Game::updateAnt(Map * map, Ant * ant, Action antAction, Coordinate coordinate) {
    //std::cout << "Update ant "<< antAction << std::endl;
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);
    std::uniform_int_distribution<unsigned> dist(Direction::TOP_RIGHT, Direction::RIGHT);
    switch(antAction) {
        case Action::EXPLORE:
            {
                Direction direction = getRandomDirection(*map, coordinate, false, false);
                ant->moveTo(map, direction);
                map->setExplored(coordinate.x, coordinate.y, true);
            }
            break;
        case Action::SEARCH_COLONY:
            {
                map->removeAnt(coordinate.x, coordinate.y, ant);
                ant->moveBackward(map);
            }
            break;
        case Action::SEARCH_FOR_FOOD:
            {
                Direction direction = getRandomDirection(*map, coordinate, true, true);
                ant->moveTo(map, direction);
                if(map->getFoodQuantity(coordinate.x, coordinate.y) > 0) {
                    map->changeFoodQuantity(coordinate.x, coordinate.y, map->getFoodQuantity(coordinate.x, coordinate.y) - 1);
                    //cast ant to worker
                    Worker * worker = dynamic_cast<Worker *>(ant);
                    if(worker != nullptr)
                        worker->setCarringFood(true);
                }
            }
            break;
        //It's the same instructions if the ant go back to the colony or if a slaver is carring larva
        case Action::GO_BACK_TO_COLONY_WITH_FOOD:
            if(ant->isAtHome()) {
                Worker * worker = dynamic_cast<Worker *>(ant);
                if(worker != nullptr) {
                    worker->setCarringFood(false);
                    colony->addFood(1);
                }
                break;
            }
        case Action::CARRING_LARVA:
            {
                map->removeAnt(coordinate.x, coordinate.y, ant);
                ant->moveBackward(map);
            }
            break;
        case Action::DIE:
            stopGame();
            return false;
        case Action::BORN:
            {
                //std::cout << map[coordinate.x][coordinate.y]->getAnts().size() << std::endl;
                Queen *queen = dynamic_cast<Queen *>(ant);
                if (queen != nullptr) {
                    ColonyAnt ** childs = queen->getChilds();
                    if(childs != nullptr) {
                        for(int i = 0; i < 2; i++) {
                            map->addAnt(coordinate.x, coordinate.y, childs[i]);
                        }
                        colony->addLarva(childs);
                        queen->born();
                    }
                    queen->born();
                }
            }
            break;
        case Action::PATROLLING:
            {
                Direction direction = getRandomDirection(*map, coordinate, true, false);
                ant->moveTo(map, direction);
            }
            break;
        case Action::COMING_HOME:
            {
                map->removeAnt(coordinate.x, coordinate.y, ant);
                ant->moveBackward(map);
            }
            break;
        case Action::ATTACK:
            {
                std::vector<Ant *> list = map[coordinate.x][coordinate.y]->getAnts();
                for (auto itr = list.cbegin(); itr != list.end(); itr++) {
                    //Get the Ant
                    Ant *ant = *itr;
                    if (dynamic_cast<Slaver *>(ant) != nullptr) {
                        list.erase(itr--);
                        break;
                    }

                }
            }
            break;
        default:
            break;
    }
    return true;
}

Direction Game::getRandomDirection(Map map, Coordinate coordinate, bool needToBeExplored, bool containFood) {

    std::vector<Direction> directions;
    std::vector<Direction> secondChoiceDirection;
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);
    std::uniform_int_distribution<unsigned> dist(0, UINT32_MAX);

    for (int direction = Direction::TOP_RIGHT; direction <= Direction::RIGHT; direction++) {
        Coordinate newCoordinate = getCoordinateWithDirection(coordinate, (Direction) direction);
        //std::cout << "Direction " << direction << " " << newCoordinate.x << " " << newCoordinate.y << std::endl;
        if (newCoordinate.x < 0 || newCoordinate.x >= WIDTH || newCoordinate.y < 0 ||
            newCoordinate.y >= HEIGHT || map[newCoordinate.x][newCoordinate.y].getTypeOfChunk() == TypeOfChunk::OBSTACLE) {
            continue;
        } else {
            if(needToBeExplored) {
                if(map[newCoordinate.x][newCoordinate.y].isExplored()) {
                    if(containFood) {
                        if (map[newCoordinate.x][newCoordinate.y].getFoodQuantity() > 0) {
                            directions.push_back((Direction) direction);
                        }else {
                            secondChoiceDirection.push_back((Direction) direction);
                        }
                    }else {
                        directions.push_back((Direction) direction);
                    }
                }
            }else {
                directions.push_back((Direction) direction);
            }
        }
    }
    if(! directions.empty()) {
        return directions[dist(mt) % directions.size()];
    }else if(! secondChoiceDirection.empty()) {
        return secondChoiceDirection[dist(mt) % secondChoiceDirection.size()];
    }else {
        return Direction::NONE;
    }

}

Colony * Game::getColony() {
    return colony;

}

void Game::stopGame() {
    isRunning = false;
}
