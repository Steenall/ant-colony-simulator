#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>
#include "view/sfml/SFMLEventHandler.hpp"
#include "view/sfml/SFMLGameEngine.hpp"
#include "model/Colony.hpp"


SFMLEventHandler::SFMLEventHandler(sf::RenderWindow * window, Game *game, SFMLGameEngine *sfmlGameEngine) {
    this->window = window;
    this->game = game;
    this->sfmlGameEngine = sfmlGameEngine;
}

void SFMLEventHandler::handleEvents() {
    sf::View *view = sfmlGameEngine->getView();
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                window->close();
            }else if(event.type == sf::Event::KeyPressed) {
                std::cout << "key pressed" << std::endl;
                if(event.key.code == sf::Keyboard::Add) {
                    view->zoom(0.9f);
                }else if(event.key.code == sf::Keyboard::Subtract) {
                    view->zoom(1.1f);
                }
            }
        }
        //Sleep 0.1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}

std::string SFMLEventHandler::buildPopup(int x, int y) {
    std::string str = "";
    if( x < game->getMap()->getWidth() && y < game->getMap()->getHeight() && x >= 0 && y >= 0 ) {
        Chunk chunk = game->getMap()->getChunks()[x][y];
        game->getColony()->getAnts();
        std::string str = "Type de case : " + std::to_string(chunk.getTypeOfChunk()) + "\n";
        str += "Pheromone : " + std::to_string(chunk.getPheromone()) + "\n";
        str += "Nourriture : " + std::to_string(chunk.getFoodQuantity()) + "\n";
        str += "Fourmis : " + std::to_string(chunk.getAnts().size());
    }
    return str;
}

void SFMLEventHandler::start() {
    sf::View *view = sfmlGameEngine->getView();
    bool showInformation = true;
    while (window->isOpen())
    {
        // Process events
        readInput();
        //Sleep 0.1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }


}

void SFMLEventHandler::terminate() {


}

void SFMLEventHandler::setView(sf::View *view) {
    this->view = view;
}

void SFMLEventHandler::readInput() {
    bool showInformation = true;

    sf::Event event;
    while (window->pollEvent(event)) {
        // Close window: exit
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::MouseWheelScrolled) {
            if(event.mouseWheelScroll.delta > 0) {

                if(view->getSize().x > 100 && view->getSize().y > 100) {
                    view->zoom(0.9f);
                }
            }else if(event.mouseWheelScroll.delta < 0) {

                if(view->getSize().x < 4000 || view->getSize().y < 4000) {
                    view->zoom(1.1f);
                }
            }
            break;
        }else if(event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Add:
                    if(view->getSize().x > 100 && view->getSize().y > 100) {
                        view->zoom(0.9f);
                    }
                    break;
                case sf::Keyboard::Subtract:
                    if(view->getSize().x < 4000 || view->getSize().y < 4000) {
                        view->zoom(1.1f);
                    }
                    break;
                case sf::Keyboard::Left:
                case sf::Keyboard::Q:
                    view->move(-CAMERA_MOVE_OFFSET, 0);
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    view->move(CAMERA_MOVE_OFFSET, 0);
                    break;
                case sf::Keyboard::Up:
                case sf::Keyboard::Z:
                    view->move(0, CAMERA_MOVE_OFFSET);
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    view->move(0, -CAMERA_MOVE_OFFSET);
                    break;
                case sf::Keyboard::I:
                    showInformation = ! showInformation;
                    break;
                default:
                    break;
            }
        }else if(event.type == sf::Event::MouseEntered || event.type == sf::Event::MouseMoved) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
            //Get world position in view
            sf::Vector2f worldPosition = window->mapPixelToCoords(mousePosition, *view);
        }
    }
    //int x = int (view->getCenter().x)/SPRITE_SIZE;
    //int y = int (view->getCenter().y)/SPRITE_SIZE;
    //std::string popup = buildPopup(x, y);
}

SFMLEventHandler::~SFMLEventHandler() = default;
