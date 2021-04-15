/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Player methods
*/


#include <iostream>
#include "Player.hpp"


// Methods
void Player::lookLeft() {
  _looking_right = false;
}

void Player::lookRight() {
  _looking_right = true;
}

std::vector<std::shared_ptr<Bullet>> Player::shoot(std::vector<std::shared_ptr<Bullet>> bullets) {
  bullets = _weapon.shoot(bullets, _looking_right);
  return bullets;
}

// Setters
void Player::setWeaponX() {
  float x_to_set = _position.x;
  if (_looking_right) {x_to_set = x_to_set + _size.x - _weapon.getSize().x;}
  _weapon.setPosition(x_to_set, _weapon.getPosition().y);
}

void Player::setWeaponY() {
  _weapon.setPosition(_weapon.getPosition().x, _position.y + getSize().y / 3.f);
}


// Getters
const float& Player::getMoveDistance() const {return _MOVE_DISTANCE;}
const float& Player::getRateOfFire() const {return _weapon.getRateOfFire();}