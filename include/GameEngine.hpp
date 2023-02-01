#ifndef ANT_COLONY_SIMULATOR_GAMEENGINE_HPP
#define ANT_COLONY_SIMULATOR_GAMEENGINE_HPP


#include "model/Map.hpp"
#include "model/Game.hpp"
#include "view/sfml/SFMLGameEngine.hpp"

#define DEFAULT_FPS 60
#define UPDATE_PER_SECOND 10
#define NUMBER_OF_FRAME_UNTIL_UPDATE (DEFAULT_FPS / UPDATE_PER_SECOND)

#define WINDOW_NAME "Ant Colony Simulator"

class GameEngine {

    public:
        explicit GameEngine(Game *game);
        void start();
        void pause();

    private :
        Colony *colony;
        Game *game;
        const unsigned defaultFPS = DEFAULT_FPS;
        SFMLGameEngine *sfmlGameEngine;
        SFMLEventHandler *sfmlEventHandler;
};


#endif //ANT_COLONY_SIMULATOR_GAMEENGINE_HPP
