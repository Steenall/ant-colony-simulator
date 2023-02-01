
#ifndef ANT_COLONY_SIMULATOR_COLONYANT_HPP
#define ANT_COLONY_SIMULATOR_COLONYANT_HPP


#include "Ant.hpp"

class ColonyAnt : public Ant {
    public:
        ColonyAnt();
        virtual Action update(Map map);
        ~ColonyAnt();
};


#endif //ANT_COLONY_SIMULATOR_COLONYANT_HPP
