/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Master methods
*/


#include "Master.hpp"


// Methods
void Master::setupWindow() {
  _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(_GAMEBOARD_SIZE_X, _GAMEBOARD_SIZE_Y), "Narcyz", sf::Style::Close);
  _window->setFramerateLimit(60);
}

const bool& Master::pollEvent(sf::Event event) const {
  return _window->pollEvent(event);
}

void Master::clearWindow() {
  _window->clear();
}


// Setters


// Getters
const std::shared_ptr<sf::RenderWindow>& Master::getWindow() const {return _window;}
const bool& Master::getOpen() const {return _window->isOpen();}