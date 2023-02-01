#include "model/Map.hpp"
#include <random>
#include <iostream>

Map::Map(unsigned width, unsigned height) {
    this->width = width;
    this->height = height;
    chunks = new Chunk*[width];
    for (int i = 0; i < width; i++) {
        chunks[i] = new Chunk[height]{};
    }
    chunks[COLONY_W][COLONY_H].setTypeOfChunk(TypeOfChunk::COLONY);
}

/**
 * Print the map (it's not the same as on the SFML view, it's rotated by 90 degrees)
 */
void Map::printMap() {
    std::cout << "┌";
    for (int j = 0; j < height-1; j++) {
        std::cout << "───┬";
    }
    std::cout << "───┐" << std::endl;
    for (int i = 0; i < width; i++) {
        std::cout << "| ";
        for (int j = 0; j < height; j++) {
            std::cout << "\033[1m";
            if(chunks[i][j].getTypeOfChunk() == TypeOfChunk::OBSTACLE) {
                std::cout << "\033[31m";
                std::cout << "O";
                //Reset the color
                std::cout << "\033[0m";
            } else if(chunks[i][j].getFoodQuantity() > 0) {
                std::cout << "\033[33m";
                std::cout << "F";
                std::cout << "\033[0m";
            }else if(chunks[i][j].getTypeOfChunk() == TypeOfChunk::COLONY) {
                std::cout << "\033[32m";
                std::cout << "C";
                std::cout << "\033[0m";
            } else {
                std::cout << " ";
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
        if(i==width-1) {
            std::cout << "└";
            for (int j = 0; j < height - 1; j++) {
                std::cout << "───┴";
            }
            std::cout << "───┘" << std::endl;
        }else {
            std::cout << "├";
            for (int j = 0; j < height - 1; j++) {
                std::cout << "───┼";
            }
            std::cout << "───┤" << std::endl;
        }
    }
}

/*bool Map::checkBorderChunksIsEmpty(unsigned x[6], unsigned y[6]) {
    for(int i=0; i<6; i++) {
        if(!checkBorderChunkIsEmpty(x[i], y[i])) {
            return false;
        }
    }
    return true;
}
bool Map::checkBorderChunkIsNotObstacle(unsigned int x, unsigned int y) {
    return (x!=0 && chunks[x-1][y].getTypeOfChunk() == TypeOfChunk::EMPTY) &&
      (x!=width-1 && chunks[x+1][y].getTypeOfChunk() == TypeOfChunk::EMPTY) &&
      (y!=0 && chunks[x][y-1].getTypeOfChunk() == TypeOfChunk::EMPTY) &&
      (y!=height-1 && chunks[x][y+1].getTypeOfChunk() == TypeOfChunk::EMPTY) &&
      (x!=0 && y!=0 && chunks[x-1][y-1].getTypeOfChunk() == TypeOfChunk::EMPTY) &&
      (x!=0 && y!=height-1 && chunks[x-1][y+1].getTypeOfChunk() == TypeOfChunk::EMPTY) &&
      (x!=width-1 && y!=0 && chunks[x+1][y-1].getTypeOfChunk() == TypeOfChunk::EMPTY) &&
      (x!=width-1 && y!=height-1 && chunks[x+1][y+1].getTypeOfChunk() == TypeOfChunk::EMPTY);

}

bool Map::checkBorderChunkIsNotType(unsigned int x, unsigned int y, TypeOfChunk chunk) {
    return !((x!=0 && chunks[x-1][y].getTypeOfChunk() == chunk) ||
            (x!=width-1 && chunks[x+1][y].getTypeOfChunk() == chunk) ||
            (y!=0 && chunks[x][y-1].getTypeOfChunk() == chunk) ||
            (y!=height-1 && chunks[x][y+1].getTypeOfChunk() == chunk) ||
            (x!=0 && y!=0 && chunks[x-1][y-1].getTypeOfChunk() == chunk) ||
            (x!=0 && y!=height-1 && chunks[x-1][y+1].getTypeOfChunk() == chunk) ||
            (x!=width-1 && y!=0 && chunks[x+1][y-1].getTypeOfChunk() == chunk) ||
            (x!=width-1 && y!=height-1 && chunks[x+1][y+1].getTypeOfChunk() == chunk));

}*/

Chunk Map::getChunk(unsigned int x, unsigned int y) {
    return chunks[x][y];
}

void Map::changeFoodQuantity(unsigned int x, unsigned int y, unsigned int quantity) {
    chunks[x][y].setFoodQuantity(quantity);
}

Chunk ** Map::getChunks() {
    return chunks;
}

void Map::changeTypeOfChunk(unsigned int x, unsigned int y, TypeOfChunk type) {
    chunks[x][y].setTypeOfChunk(type);
}

unsigned Map::getHeight() const {
    return height;
}

unsigned Map::getWidth() const {
    return width;
}

Chunk * Map::operator[](unsigned int x) {
    return chunks[x];
}

Chunk Map::operator[](Coordinate coordinate) {
    return chunks[coordinate.x][coordinate.y];
}

void Map::addAnt(unsigned int x, unsigned int y, Ant *ant) {
    chunks[x][y].addAnt(ant);
}

void Map::removeAnt(unsigned int x, unsigned int y, Ant *ant) {
    chunks[x][y].removeAnt(ant);
}

void Map::setExplored(unsigned int x, unsigned int y, bool b) {
    chunks[x][y].setExplored(b);
}

unsigned int Map::getFoodQuantity(unsigned int x, unsigned int y) {
    return chunks[x][y].getFoodQuantity();
}

Map::~Map() = default;

Coordinate::Coordinate(unsigned x, unsigned y) {
    this->x = x;
    this->y = y;
}

Coordinate::Coordinate() {
    x = 0;
    y = 0;
}
