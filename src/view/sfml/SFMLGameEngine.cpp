#include <SFML/Graphics.hpp>
#include <iostream>
#include "view/sfml/SFMLGameEngine.hpp"
#include "model/Map.hpp"
#include "model/Slaver.hpp"
#include "view/sfml/SFMLEventHandler.hpp"
#include "model/Game.hpp"
#include "model/Colony.hpp"
#include "GameEngine.hpp"


SFMLGameEngine::SFMLGameEngine(sf::RenderWindow *window, Game *game) {
    this->window = window;
    this->game = game;
    this->width = window->getSize().x;
    this->height = window->getSize().y;
    view = new sf::View(sf::FloatRect(0, 0, width, height));
    view->move(width/3, height);
    createTexture();
    popup.setPosition(0,0);
    popup.setString("");
}

void SFMLGameEngine::setSFMLEventHandler(SFMLEventHandler *control) {
    this->control = control;
    control->setView(view);
}

void SFMLGameEngine::createTexture() {
    colonyTexture.loadFromFile("resources/mud.png");
    foodTexture.loadFromFile("resources/bread.png");
    grassTexture.loadFromFile("resources/grass.jpeg");
    grassTextureNotVisited.loadFromFile("resources/grass_notvisited.jpeg");
    rockTexture.loadFromFile("resources/rock.jpeg");
    workerTexture.loadFromFile("resources/worker.png");
    slaverTexture.loadFromFile("resources/slaver.png");
    soldierTexture.loadFromFile("resources/soldier.png");
    scoutTexture.loadFromFile("resources/scout.png");
    font.loadFromFile("resources/batmfa.ttf");
}

void SFMLGameEngine::fillMap(sf::RenderTexture * renderTexture) {
    Map * map = game->getMap();
    Chunk ** chunks = map->getChunks();
    int countFood = 0;
    for (int i = 0; i < map->getWidth(); i++) {
        for (int j = 0; j < map->getHeight(); j++) {
            sf::RectangleShape rectangle(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
            rectangle.setPosition(i * SPRITE_SIZE, j * SPRITE_SIZE);
            switch (chunks[i][j].getTypeOfChunk()) {
                case TypeOfChunk::OBSTACLE:
                    rectangle.setTexture(&rockTexture);
                    break;
                case TypeOfChunk::COLONY: {
                    rectangle.setTexture(&colonyTexture);
                    sf::RectangleShape rectangle2(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
                    rectangle2.setPosition(i * SPRITE_SIZE, j * SPRITE_SIZE);
                    rectangle2.setTexture(&grassTexture);
                    renderTexture->draw(rectangle2);
                    break;
                }
                default:
                    if(chunks[i][j].isExplored())
                        rectangle.setTexture(&grassTexture);
                    else
                        rectangle.setTexture(&grassTextureNotVisited);
                    break;
            }
            renderTexture->draw(rectangle);
            if(chunks[i][j].getFoodQuantity() > 0){
                countFood++;
                sf::RectangleShape rectangle2(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
                rectangle2.setPosition(i * SPRITE_SIZE, j * SPRITE_SIZE);
                rectangle2.setTexture(&foodTexture);
                renderTexture->draw(rectangle2);
            }
        }
    }
}

void SFMLGameEngine::addAnts(sf::RenderTexture * renderTexture) {
    for (Ant *ant : game->getColony()->getAnts()) {
        sf::RectangleShape rectangle(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
        rectangle.setPosition(ant->getCoordinate().x * SPRITE_SIZE, ant->getCoordinate().y * SPRITE_SIZE);

        if (dynamic_cast<Worker *>(ant) != nullptr) {
            //std::cout << "Worker" << std::endl;
            rectangle.setTexture(&workerTexture);
        } else if (dynamic_cast<Slaver *>(ant) != nullptr) {
            //std::cout << "Slaver" << std::endl;
            rectangle.setTexture(&slaverTexture);
        } else if (dynamic_cast<Soldier *>(ant) != nullptr) {
            //std::cout << "Soldier" << std::endl;
            rectangle.setTexture(&soldierTexture);
        } else if (dynamic_cast<Scout *>(ant) != nullptr) {
            //std::cout << "Scout" << std::endl;
            rectangle.setTexture(&scoutTexture);
        }else {
            continue;
        }
        //else, it's the queen, we don't draw it

        renderTexture->draw(rectangle);
    }

    sf::RectangleShape rectangle(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    rectangle.setPosition(0, 0);
    rectangle.setTexture(&slaverTexture);
    renderTexture->draw(rectangle);
}

void SFMLGameEngine::renderingFunction() {
    std::cout << "renderingFunction" << std::endl;
    //Add a render texture
    sf::RenderTexture * renderTexture;
    renderTexture = new sf::RenderTexture();
    if (!renderTexture->create(width, height))
    {
        exit(1);
    }
    popup.setFont(font);
    int countFPSUntilUpdateAnts = NUMBER_OF_FRAME_UNTIL_UPDATE;
    while (window->isOpen())
    {
        window->setActive(true);
        //popupMutex.lock();
        renderTexture->clear();
        window->clear();
        fillMap(renderTexture);
        addAnts(renderTexture);
        //addPopup(renderTexture);
        //Set the view to the render texture
        renderTexture->setView(*view);
        window->draw(sf::Sprite(renderTexture->getTexture()));
        // end the current frame
        window->display();
        window->setActive(false);
        control->readInput();
        countFPSUntilUpdateAnts--;
        if(countFPSUntilUpdateAnts == 0){
            game->updateAllAnts();
            countFPSUntilUpdateAnts = NUMBER_OF_FRAME_UNTIL_UPDATE;
        }
    }
}

void SFMLGameEngine::start() {
    thread = new sf::Thread(&SFMLGameEngine::renderingFunction, this);
    thread->launch();
}

sf::RenderWindow *SFMLGameEngine::getWindow() {
    return window;
}

void SFMLGameEngine::stop() {
    thread->wait();
    thread->launch();
}



void SFMLGameEngine::terminate() {
    thread->terminate();

}

sf::View * SFMLGameEngine::getView() {
    return view;

}

void SFMLGameEngine::setPopup(std::string text, int x, int y) {
    popup.setString(text);
}

void SFMLGameEngine::addPopup(sf::RenderTexture *pTexture) {
    if(popup.getString() != ""){
        std::cout << "add popup" << std::endl;
        pTexture->draw(popup);
    }
}