#ifndef ANT_COLONY_SIMULATOR_SFMLGAMEENGINE_HPP
#define ANT_COLONY_SIMULATOR_SFMLGAMEENGINE_HPP

#include <SFML/Graphics.hpp>
#include "model/Map.hpp"
#include "model/Game.hpp"
#include "SFMLEventHandler.hpp"

#define SPRITE_SIZE 30

class SFMLGameEngine{
    public:
        SFMLGameEngine(sf::RenderWindow *window, Game *game);
        void createTexture();
        void renderingFunction();
        void fillMap(sf::RenderTexture * renderTexture);
        void start();
        void stop();
        void terminate();
        sf::RenderWindow *getWindow();
        sf::View * getView();
        void setPopup(std::string text, int x, int y);
        void setSFMLEventHandler(SFMLEventHandler *control);
    private:
        sf::Texture colonyTexture;
        sf::Texture foodTexture;
        sf::Texture grassTexture;
        sf::Texture grassTextureNotVisited;
        sf::Texture rockTexture;
        sf::Texture workerTexture;
        sf::Texture slaverTexture;
        sf::Texture soldierTexture;
        sf::Texture scoutTexture;

        sf::Font font;
        sf::Text popup;

        sf::Thread* thread;
        sf::RenderWindow *window;
        sf::View * view;
        SFMLEventHandler *control;
        Game * game;

        unsigned int height;
        unsigned int width;

        void addAnts(sf::RenderTexture *renderTexture);

        void addPopup(sf::RenderTexture *pTexture);

};


#endif //ANT_COLONY_SIMULATOR_SFMLGAMEENGINE_HPP
