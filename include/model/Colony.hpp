
#ifndef ANT_COLONY_SIMULATOR_COLONY_HPP
#define ANT_COLONY_SIMULATOR_COLONY_HPP


#include "Worker.hpp"
#include "Soldier.hpp"
#include "Scout.hpp"
#include "Queen.hpp"
#include <vector>

class Colony {
    public:
        Colony();
        void update();
        void addLarva(ColonyAnt ** larva);
        std::vector<Ant *> getAnts();
        unsigned getDay();
        unsigned long getFoodQuantity();
        void addFood(unsigned food);
        ~Colony();

    void incrementDay();

private:
        std::vector<Ant*> listAnt;
        Queen * queen;
        unsigned long foodStock;
        unsigned days;
};


#endif //ANT_COLONY_SIMULATOR_COLONY_HPP
