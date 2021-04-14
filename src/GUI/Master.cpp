/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Master methods
*/


#include "Master.hpp"
#include <iostream>


// Methods
void Master::setupWindow() {
  _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(_GAMEBOARD_SIZE_X, _GAMEBOARD_SIZE_Y), "Narcyz", sf::Style::Default);
  _window->setFramerateLimit(60);
}

void Master::setupPlayerTextures() {
  _player_texture = std::make_shared<sf::Texture>();
  _player_texture->loadFromFile("../img/player.png");
  _player_falling_texture = std::make_shared<sf::Texture>();
  _player_falling_texture->loadFromFile("../img/player_falling.png");
}

void Master::clearWindow() {
  _window->clear();
}

void Master::drawRectangle(sf::RectangleShape rectangle) {
  _window->draw(rectangle);
}

void Master::drawSprite(sf::Sprite sprite) {
  _window->draw(sprite);
}

void Master::displayWindow() {
  _window->display();
}

void Master::closeWindow() {
  _window->close();
}


// Setters


// Getters
std::shared_ptr<sf::RenderWindow>& Master::getWindow() {return _window;}
std::shared_ptr<sf::Texture>& Master::getPlayerTexture() {return _player_texture;}
std::shared_ptr<sf::Texture>& Master::getPlayerFallingTexture() {return _player_falling_texture;}
bool Master::getOpen() {return _window->isOpen();}