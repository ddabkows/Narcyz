/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Bullet methods
*/


#include "Bullet.hpp"


// Getters
const float& Bullet::getMoveDistance() const {return _MOVE_DISTANCE;}
const bool& Bullet::getLookingRight() const {return _looking_right;}