
#ifndef ANT_COLONY_SIMULATOR_QUEEN_HPP
#define ANT_COLONY_SIMULATOR_QUEEN_HPP

#include "ColonyAnt.hpp"
#include "Ant.hpp"

#define NUMBER_OF_BABY_PER_ROUND 2

class Queen : public ColonyAnt {
    public:
        Queen();
        bool canlayEggs();
        void agressed();
        ColonyAnt ** getChilds();
        Action update(Map map) override;
        void born();
        static ColonyAnt ** createLarva(Coordinate coordinate);
        ~Queen();
    private:
        unsigned currentAge;
        bool isAgressed;
        ColonyAnt **currentChilds;
};


#endif //ANT_COLONY_SIMULATOR_QUEEN_HPP
