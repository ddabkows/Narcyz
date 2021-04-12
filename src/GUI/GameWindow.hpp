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

  public:
    // Constructor
    GameWindow() {}

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