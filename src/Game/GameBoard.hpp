/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of GameBoard
*/


#include "Dimensions.hpp"


#ifndef _GAME_BOARD_H_
#define _GAME_BOARD_H_


class GameBoard {
  private:
    // Trait
    using myClass = GameBoard;
    Dimensions _inside_limits;
    
  public:
    // Constructor
    GameBoard(int size_x, int size_y) : _inside_limits() {
      setSize(size_x, size_y);
    }

    // Copy
    GameBoard(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameBoard(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods

    // Setters
    void setSize(int, int);

    // Getters
    const Dimensions& getSize() const;

    // Destructor
    ~GameBoard() = default;
};
#endif