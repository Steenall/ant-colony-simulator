#ifndef ANT_COLONY_SIMULATOR_ANT_HPP
#define ANT_COLONY_SIMULATOR_ANT_HPP


#include "Action.hpp"
#include "model/Direction.hpp"
#include "Coordinate.hpp"
#include "Map.hpp"
#include <vector>

class Ant {
    public:
        Ant();
        virtual Action update(Map map);
        Coordinate getCoordinate();
        void setCoordinate(Coordinate coordinate);
        void moveBackward(Map * map);
        void moveTo(Map * map, Direction direction);
        void setHomeCoordinate(Coordinate coordinate);
        bool operator==(const Ant& other) const;
        bool isAtHome();
        ~Ant();
    protected:
        std::vector<Direction> pathing;
        int countChunks;
        Coordinate coordinate;
        Coordinate homeCoordinate;
        static unsigned long idCount;
        unsigned long id;
};


#endif //ANT_COLONY_SIMULATOR_ANT_HPP
