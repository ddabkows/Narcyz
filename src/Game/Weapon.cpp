/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Weapon methods
*/


#include "Weapon.hpp"
#include <iostream>


// Methods
std::vector<std::shared_ptr<Bullet>> Weapon::shoot(std::vector<std::shared_ptr<Bullet>> bullets, bool looking_right) {
  float position_to_set = _position.x;
  float direction = 1.f;
  if (!looking_right) {
    direction = -direction;
    position_to_set -= 10.f;
  }
  else {position_to_set += _size.x + 10.f;}
  bullets.emplace_back(std::make_shared<Bullet>(10.f, 4.f, position_to_set, _position.y, direction * _bullet_speed, _damage, looking_right));

  return bullets;
}


// Getters
const float& Weapon::getRateOfFire() const {return _rate_of_fire;}