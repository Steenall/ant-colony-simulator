#ifndef ANT_COLONY_SIMULATOR_GAME_HPP
#define ANT_COLONY_SIMULATOR_GAME_HPP


#include "Map.hpp"
#include "Action.hpp"

class Game {
    private:
        Map * map;
        Colony * colony;
        ColonyEvolutionExporter * exporter;
        bool isRunning;

    public:
        Game(Map * map, Colony * colony);
        Map *getMap();
        void updateAllAnts();
        Colony * getColony();
        void stopGame();
        bool updateAnt(Map * map, Ant * ant, Action antAction, Coordinate coordinate);
        static Direction getRandomDirection(Map map, Coordinate coordinate, bool needToBeExplored, bool containFood);
};


#endif //ANT_COLONY_SIMULATOR_GAME_HPP
