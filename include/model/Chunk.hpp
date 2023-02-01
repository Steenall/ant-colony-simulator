
#ifndef ANT_COLONY_SIMULATOR_CHUNK_HPP
#define ANT_COLONY_SIMULATOR_CHUNK_HPP

#include <vector>
#include "TypeOfChunk.hpp"
#include "Direction.hpp"

class Ant;

class Chunk {
    public:
        Chunk(TypeOfChunk type=TypeOfChunk::EMPTY , unsigned foodQuantity=0);
        void setFoodQuantity(unsigned foodQuantity);
        void setTypeOfChunk (TypeOfChunk type);
        TypeOfChunk getTypeOfChunk();
        unsigned int getFoodQuantity();
        void setPheromone(unsigned int pheromone);
        unsigned int getPheromone();
        bool isExplored();
        void setExplored(bool explored);
        void addAnt(Ant *ant);
        void removeAnt(Ant *ant);
        std::vector<Ant *> getAnts();
        void setAnts(std::vector<Ant *> ants);
        ~Chunk();
    private:
        TypeOfChunk typeOfChunk;
        unsigned  foodQuantity;
        bool explored;
        unsigned pheromomeQuantity;
        std::vector<Ant*> listAnt;

};


#endif //ANT_COLONY_SIMULATOR_CHUNK_HPP
