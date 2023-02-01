
#ifndef ANT_COLONY_SIMULATOR_SOLDIER_HPP
#define ANT_COLONY_SIMULATOR_SOLDIER_HPP

#include "ColonyAnt.hpp"

class Soldier : public ColonyAnt {
    public:
        Soldier();
        Action update(Map map) override;
        bool isComingHome();
        ~Soldier();
    private:
        unsigned dayBeforeComingHome;
        bool comingHome;
};


#endif //ANT_COLONY_SIMULATOR_SOLDIER_HPP
