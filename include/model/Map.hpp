
#ifndef ANT_COLONY_SIMULATOR_MAP_HPP
#define ANT_COLONY_SIMULATOR_MAP_HPP


#include "../export/ColonyEvolutionExporter.hpp"
#include "Chunk.hpp"

#define WIDTH 101
#define HEIGHT 101
#define COLONY_W (WIDTH/2)
#define COLONY_H (HEIGHT/2)

#define NUMBER_OF_CHUNK WIDTH*HEIGHT

#define NUMBER_OF_FOOD (NUMBER_OF_CHUNK * 0.02)
#define QUANTITY_OF_FOOD 10
#define BIG_STOCK_OF_FOOD_NUMBER 2
#define NUMBER_CHUNK_BIG_STOCK_OF_FOOD 5
#define BIG_STOCK_OF_FOOD_QUANTITY 100000

#define NUMBER_OF_OBSTACLE_MULTIPLIER 0.30
#define NUMBER_OF_OBSTACLE (NUMBER_OF_CHUNK * NUMBER_OF_OBSTACLE_MULTIPLIER)
#define NUMBER_OF_OBSTACLE_OF_SIZE_6 ((NUMBER_OF_OBSTACLE * 0.01) / 6)
#define NUMBER_OF_OBSTACLE_OF_SIZE_5 ((NUMBER_OF_OBSTACLE * 0.04) / 5)
#define NUMBER_OF_OBSTACLE_OF_SIZE_4 ((NUMBER_OF_OBSTACLE * 0.05) / 4)
#define NUMBER_OF_OBSTACLE_OF_SIZE_3 ((NUMBER_OF_OBSTACLE * 0.1) / 3)
#define NUMBER_OF_OBSTACLE_OF_SIZE_2 ((NUMBER_OF_OBSTACLE * 0.3) /2)
#define NUMBER_OF_OBSTACLE_OF_SIZE_1 (NUMBER_OF_OBSTACLE * 0.5)

#include "model/Coordinate.hpp"

class Map {
    public:
        Map(unsigned width=WIDTH, unsigned height=HEIGHT);
        void printMap();
        Chunk getChunk(unsigned int x, unsigned int y);
        void changeFoodQuantity(unsigned int x, unsigned int y, unsigned int quantity);
        unsigned getFoodQuantity(unsigned int x, unsigned int y);
        Chunk ** getChunks();
        void changeTypeOfChunk(unsigned int x, unsigned int y, TypeOfChunk type);
        unsigned int getHeight() const;
        unsigned int getWidth() const;
        Chunk * operator[](unsigned int x);
        Chunk operator[](Coordinate coordinate);
        void addAnt(unsigned int x, unsigned int y, Ant * ant);
        void removeAnt(unsigned int x, unsigned int y, Ant * ant);
        void setExplored(unsigned int x, unsigned int y, bool b);
        ~Map();
    private:
        unsigned width;
        unsigned height;
        Chunk ** chunks;
};


#endif //ANT_COLONY_SIMULATOR_MAP_HPP
