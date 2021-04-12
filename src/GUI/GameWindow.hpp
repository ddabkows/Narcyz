/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for rectangle shapes
*/


#include "Rectangle.hpp"


#ifndef _GAME_WINDOW_H_
#define _GAME_WINDOW_H_


class GameWindow {
  private:
    // Trait
    using myClass = GameWindow;

    Rectangle _background;

  public:
    // Constructor
    GameWindow() : _background(800.f, 600.f, 0.f, 0.f, sf::Color(0, 0, 0, 255), sf::Color(0, 0, 0, 255), 0.f, 0.f) {}

    // Copy
    GameWindow(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameWindow(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods

    // Setters

    // Getters

    // Destructor
    ~GameWindow() = default;
};
#endif