
#ifndef ANT_COLONY_SIMULATOR_WORKER_HPP
#define ANT_COLONY_SIMULATOR_WORKER_HPP

#include "ColonyAnt.hpp"

class Worker : public ColonyAnt {
    public:
        Worker();
        void setCarringFood(bool carringFood);
        bool isCarringFood();
        bool isMinor();
        Action update(Map map) override;
        ~Worker();
    private:
        bool carringFood;
        unsigned dayBeforeMajority;
};


#endif //ANT_COLONY_SIMULATOR_WORKER_HPP
