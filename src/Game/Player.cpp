/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Player methods
*/


#include "Player.hpp"


// Methods
void Player::lookLeft() {
  _looking_left = true;
  _looking_right = false;
}

void Player::lookRight() {
  _looking_right = true;
  _looking_left = false;
}

void Player::shoot(std::vector<Bullet> bullets) {
  _weapon.shoot(bullets, _looking_right);
}

// Setters


// Getters
const float& Player::getMoveDistance() const {return _MOVE_DISTANCE;}