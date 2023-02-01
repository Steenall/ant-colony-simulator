
#ifndef ANT_COLONY_SIMULATOR_SCOUT_HPP
#define ANT_COLONY_SIMULATOR_SCOUT_HPP

#include "ColonyAnt.hpp"

class Scout : public ColonyAnt {
    public:
        Scout();
        bool isMinor();
        Action update(Map map) override;
        ~Scout();
    private:
       unsigned dayBeforeMajority;

};


#endif //ANT_COLONY_SIMULATOR_SCOUT_HPP
