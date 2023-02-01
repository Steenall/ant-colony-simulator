#ifndef ANT_COLONY_SIMULATOR_SFMLEVENTHANDLER_HPP
#define ANT_COLONY_SIMULATOR_SFMLEVENTHANDLER_HPP

#include "model/Game.hpp"
#define CAMERA_MOVE_OFFSET 50

class SFMLGameEngine;

class SFMLEventHandler {

    public:
        SFMLEventHandler(sf::RenderWindow * window, Game *game, SFMLGameEngine *sfmlGameEngine);
        void start();
        void terminate();
        void readInput();
        void setView(sf::View *view);
        ~SFMLEventHandler();

    private:
        sf::RenderWindow *window;
        Game *game;
        SFMLGameEngine *sfmlGameEngine;
        sf::View *view;
        sf::Thread *thread;

        void handleEvents();
        std::string buildPopup(int x, int y);
};


#endif //ANT_COLONY_SIMULATOR_SFMLEVENTHANDLER_HPP
