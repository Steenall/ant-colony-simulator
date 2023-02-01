#include "util/MapBuilder.hpp"
#include "model/Map.hpp"
#include <random>
#include <chrono>
#include <iostream>


MapBuilder::MapBuilder(unsigned int width, unsigned int height, bool borderCanCollide) {
    //init random generator
    long seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); //seed for random generator
    mt = std::mt19937(seed);
    dist_x = std::uniform_int_distribution<unsigned>(0, width-1); //distribution for x coordinate
    dist_y = std::uniform_int_distribution<unsigned>(0, height-1); //distribution for y coordinate
    dist = std::uniform_int_distribution<unsigned>(0, INT32_MAX); //distribution for other thing (like for boolean)

    this->width = width;
    this->height = height;
    this->obstacleCanCollide = borderCanCollide;
    map = new Map(width, height);
    for (int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            freeChunks.emplace_back(i, j);
        }
    }
    freeChunks.remove(Coordinate(COLONY_W, COLONY_H));
}

/**
 * Add obstacles to the map and look if they don't collide
 * @param number
 * @param size
 */
void MapBuilder::addObstacles(unsigned int number=1, unsigned int size=1) {
    std::list <Coordinate> toRemove;
    for(int i=0; i<number;i++) {
        unsigned x[size], y[size];
        int j;
        /**
         * Select a random free chunk for the base of the obstacle
         */
        unsigned index = dist(mt) % freeChunks.size();
        auto it = freeChunks.begin();
        std::advance(it, index);
        x[0] = it->x;
        y[0] = it->y;
        toRemove.emplace_back(x[0], y[0]);
        /**
         * Choose the others chunks of the obstacle randomly
         */
        for(j=1; j<size;j++) {
            int k;
            Coordinate c = Coordinate(UINT32_MAX, UINT32_MAX); // Create an object that can't be in the list freeChunks
            /**
             * Try 10 times to find a free chunk if the selected one is not free
             */
            for(k=0; k<10 && !(std::find(freeChunks.begin(), freeChunks.end(), c) != freeChunks.end()); k++) {
                if (dist(mt) % 2 == 0) { // 50% chance to move in x direction and 50% in y direction
                    if (x[j - 1] == 0) { // if the chunk is on the left border, move only in positive x direction
                        x[j] = x[j - 1] + 1;
                    } else if (x[j - 1] == width - 1) { // if the chunk is on the right border, move only in negative x direction
                        x[j] = x[j - 1] - 1;
                    } else { // else choose randomly to move in negative or positive x direction
                        if (dist(mt) % 2 == 0) {
                            x[j] = x[j - 1] + 1;
                        } else {
                            x[j] = x[j - 1] - 1;
                        }
                    }
                    y[j] = y[j - 1];
                } else {
                    if (y[j - 1] == 0) { // if the chunk is on the top border, move only in positive y direction
                        y[j] = y[j - 1] + 1;
                    } else if (y[j - 1] == height - 1) { // if the chunk is on the bottom border, move only in negative y direction
                        y[j] = y[j - 1] - 1;
                    } else { // else choose randomly to move in negative or positive y direction
                        if (dist(mt) % 2 == 0) {
                            y[j] = y[j - 1] + 1;
                        } else {
                            y[j] = y[j - 1] - 1;
                        }
                    }
                    x[j] = x[j - 1];
                }
                c = Coordinate(x[j], y[j]);
            }
            /**
             * If it's not possible to find a free chunk, we restart the creation of the obstacle from the base
             */
            if(k==10) {
                j=0;
                toRemove.clear();
                toRemove.emplace_back(x[0], y[0]);
            }else {
                toRemove.emplace_back(x[j], y[j]);
            }
        }
        /**
         * Add the obstacle to the map and remove all the chunks of the obstacle and their border chunks from the free chunks
         */
        for(j=0; j<size;j++) {

            map->changeTypeOfChunk(x[j], y[j], TypeOfChunk::OBSTACLE);
            if(!obstacleCanCollide) {
                freeChunks.remove(Coordinate(x[j]-1, y[j]));
                freeChunks.remove(Coordinate(x[j], y[j]-1));
                freeChunks.remove(Coordinate(x[j], y[j]+1));
                freeChunks.remove(Coordinate(x[j]+1, y[j]));
            }
            freeChunks.remove(Coordinate(x[j], y[j]));
        }
        toRemove.clear();
    }
}

void MapBuilder::addFood(unsigned int number, unsigned int quantity) {
    for(int i=0; i< number; i++) {
        unsigned x, y;
        do {
            x = (unsigned) dist_x(mt);
            y = (unsigned) dist_y(mt);
        }while(map->getChunk(x,y).getTypeOfChunk() != TypeOfChunk::EMPTY);
        map->changeFoodQuantity(x,y,quantity);
    }
}

Map * MapBuilder::getMap() {
    return map;
}

MapBuilder::~MapBuilder() = default;