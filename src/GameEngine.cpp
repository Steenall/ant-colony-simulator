#include <SFML/Graphics.hpp>
#include <thread>
#include "GameEngine.hpp"
#include "model/Map.hpp"
#include "view/sfml/SFMLGameEngine.hpp"
#include "view/sfml/SFMLEventHandler.hpp"
#include "model/Game.hpp"
#include "model/Colony.hpp"


void GameEngine::start() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1600, 900), WINDOW_NAME);

    window.setFramerateLimit(defaultFPS);


    // Init the SFML GameEngine
    sfmlGameEngine = new SFMLGameEngine(&window, game);
    sfmlEventHandler = new SFMLEventHandler(&window, game, sfmlGameEngine);
    sfmlGameEngine->setSFMLEventHandler(sfmlEventHandler);
    sfmlGameEngine->renderingFunction();


    //Init the SFML Event Handler
    //SFMLEventHandler * sfmlEventHandler = new SFMLEventHandler(&window, game, sfmlGameEngine);
    //sfmlEventHandler->start();



    // Start the game loop
    /*while (window.isOpen())
    {
        //std::this_thread::sleep_for(std::chrono::milliseconds(200));

        // Update all ants
        //game->updateAllAnts();

    }*/
    //sfmlGameEngine->terminate();

    //sfmlEventHandler->terminate();


}

void GameEngine::pause() {

}

GameEngine::GameEngine(Game * game) {
    this->game = game;
    colony = new Colony();
}

void nextRound() {

}