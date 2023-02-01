#include <iostream>
#include <random>
#include "util/MapBuilder.hpp"
#include "GameEngine.hpp"
#include "model/Game.hpp"
#include "model/Map.hpp"
#include "model/Colony.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32

    //Activate ascii color support on windows

    SetConsoleOutputCP(CP_UTF8);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hConsole, &dwMode);
    dwMode |= 0x0004;
    SetConsoleMode(hConsole, dwMode);

    #endif
    auto * mg = new MapBuilder();
    mg->addObstacles(NUMBER_OF_OBSTACLE_OF_SIZE_6, 6);
    std::cout << "Génération des obstacles de taille 6 "  << NUMBER_OF_OBSTACLE_OF_SIZE_6 << std::endl;
    mg->addObstacles(NUMBER_OF_OBSTACLE_OF_SIZE_5, 5);
    std::cout << "Génération des obstacles de taille 5 " << NUMBER_OF_OBSTACLE_OF_SIZE_5  << std::endl;
    mg->addObstacles(NUMBER_OF_OBSTACLE_OF_SIZE_4, 4);
    std::cout << "Génération des obstacles de taille 4 " << NUMBER_OF_OBSTACLE_OF_SIZE_4  << std::endl;
    mg->addObstacles(NUMBER_OF_OBSTACLE_OF_SIZE_3, 3);
    std::cout << "Génération des obstacles de taille 3 " << NUMBER_OF_OBSTACLE_OF_SIZE_3  << std::endl;
    mg->addObstacles(NUMBER_OF_OBSTACLE_OF_SIZE_2, 2);
    std::cout << "Génération des obstacles de taille 2 " << NUMBER_OF_OBSTACLE_OF_SIZE_2  << std::endl;
    mg->addObstacles(NUMBER_OF_OBSTACLE_OF_SIZE_1, 1);
    std::cout << "Génération des obstacles de taille 1 " << NUMBER_OF_OBSTACLE_OF_SIZE_1 << std::endl;
    mg->addFood(NUMBER_OF_FOOD, QUANTITY_OF_FOOD);
    Map * map = mg->getMap();
    //map->printMap();
    Colony * colony = new Colony();
    Game * game = new Game(map, colony);
    GameEngine * gameEngine = new GameEngine(game);
    gameEngine->start();
}