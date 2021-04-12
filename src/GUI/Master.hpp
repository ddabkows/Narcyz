/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game
*/


#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#ifndef _MASTER_H_
#define _MASTER_H_


struct Master {
  std::shared_ptr<sf::RenderWindow> window;
};
#endif