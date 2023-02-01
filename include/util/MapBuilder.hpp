#ifndef ANT_COLONY_SIMULATOR_MAPBUILDER_HPP
#define ANT_COLONY_SIMULATOR_MAPBUILDER_HPP


#include "model/Map.hpp"
#include <random>
#include <valarray>
#include <list>

class MapBuilder {
    public:
        MapBuilder(unsigned int width=WIDTH, unsigned int height=HEIGHT, bool borderCanCollide=true);
        void addObstacles(unsigned number, unsigned size);
        void addFood(unsigned number, unsigned quantity);
        Map *getMap();
        ~MapBuilder();
    private:
        unsigned width, height;
        std::list<Coordinate> freeChunks;
        Map * map;
        bool obstacleCanCollide;

        //Random generator and distribution
        std::mt19937 mt;
        std::uniform_int_distribution<unsigned> dist, dist_x, dist_y;
};


#endif //ANT_COLONY_SIMULATOR_MAPBUILDER_HPP
