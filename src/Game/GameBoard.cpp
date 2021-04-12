/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameBoard methods
*/


#include "GameBoard.hpp"


void GameBoard::setSize(int size_x, int size_y) {
  /*
    Method made to set the size of the GameInsideBounds
  */

  _inside_limits.x = size_x;
  _inside_limits.y = size_y;
}