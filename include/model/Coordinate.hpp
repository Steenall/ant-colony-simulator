#ifndef ANT_COLONY_SIMULATOR_COORDINATE_HPP
#define ANT_COLONY_SIMULATOR_COORDINATE_HPP


class Coordinate {
    public:
        Coordinate(unsigned x, unsigned y);
        Coordinate();
        bool operator == (const Coordinate& c) const { return x == c.x && y == c.y; };
        unsigned x;
        unsigned y;
};


#endif //ANT_COLONY_SIMULATOR_COORDINATE_HPP
