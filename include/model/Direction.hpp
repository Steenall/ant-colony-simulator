
#ifndef ANT_COLONY_SIMULATOR_DIRECTION_HPP
#define ANT_COLONY_SIMULATOR_DIRECTION_HPP

#include "Coordinate.hpp"

enum Direction {
    NONE = -1,
    TOP_RIGHT = 0,
    TOP = 1,
    TOP_LEFT = 2,
    LEFT = 3,
    BOTTOM_LEFT = 4,
    BOTTOM = 5,
    BOTTOM_RIGHT = 6,
    RIGHT = 7
};

Direction getOppositeDirection(Direction direction);

Coordinate getCoordinateWithDirection(Coordinate coordinate, Direction direction);

#endif //ANT_COLONY_SIMULATOR_DIRECTION_HPP
