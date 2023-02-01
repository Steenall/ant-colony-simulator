
#ifndef ANT_COLONY_SIMULATOR_SLAVER_HPP
#define ANT_COLONY_SIMULATOR_SLAVER_HPP

#include "Ant.hpp"

class Slaver : public Ant {
    public:
        Slaver();
        bool carringLarva();
        Action update(Map map) override;
        ~Slaver();
    private:
        bool isCarringLarva;
};


#endif //ANT_COLONY_SIMULATOR_SLAVER_HPP
