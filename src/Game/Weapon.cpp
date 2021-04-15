/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Weapon methods
*/


#include "Weapon.hpp"


// Methods
void Weapon::shoot(std::vector<Bullet> bullets, bool looking_right) {
  float position_to_set = _position.x;
  if (looking_right) {position_to_set += _size.x;}
  bullets.emplace_back(3.f, 2.f, position_to_set, _position.y, _bullet_speed, looking_right);
}


// Getters
const float& Weapon::getRateOfFire() const {return _rate_of_fire;}