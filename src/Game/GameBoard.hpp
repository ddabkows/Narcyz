/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
*/


#include "Dimensions.hpp"


#ifndef _GAME_BOARD_H_
#define _GAME_BOARD_H_


class GameBoard {
  private:
    // Trait
    using myClass = GameBoard;
    
  public:
    // Constructor
    GameBoard() {}

    // Copy
    GameBoard(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameBoard(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Destructor
    ~GameBoard() = default;
};
#endif