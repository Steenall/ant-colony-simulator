#include "model/Direction.hpp"
#include "model/Coordinate.hpp"

Direction getOppositeDirection(Direction direction) {
    switch (direction) {
        case TOP_RIGHT:
            return BOTTOM_LEFT;
        case TOP:
            return BOTTOM;
        case TOP_LEFT:
            return BOTTOM_RIGHT;
        case LEFT:
            return RIGHT;
        case BOTTOM_LEFT:
            return TOP_RIGHT;
        case BOTTOM:
            return TOP;
        case BOTTOM_RIGHT:
            return TOP_LEFT;
        case RIGHT:
            return LEFT;
        default:
            return NONE;
    }
}

Coordinate getCoordinateWithDirection(Coordinate coordinate, Direction direction) {
    switch (direction) {
        case TOP_RIGHT:
            return {coordinate.x + 1, coordinate.y - 1};
        case TOP:
            return {coordinate.x, coordinate.y - 1};
        case TOP_LEFT:
            return {coordinate.x - 1, coordinate.y - 1};
        case LEFT:
            return {coordinate.x - 1, coordinate.y};
        case BOTTOM_LEFT:
            return {coordinate.x - 1, coordinate.y + 1};
        case BOTTOM:
            return {coordinate.x, coordinate.y + 1};
        case BOTTOM_RIGHT:
            return {coordinate.x + 1, coordinate.y + 1};
        case RIGHT:
            return {coordinate.x + 1, coordinate.y};
        default:
            return {coordinate.x, coordinate.y};
    }
}