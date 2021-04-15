/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Weapon
*/


#include <vector>
#include "GameEntity.hpp"
#include "Bullet.hpp"


#ifndef _WEAPON_H_
#define _WEAPON_H_

class Weapon : public GameEntity {
private:
  // Trait
  using myClass = Weapon;

  float _rate_of_fire;
  float _damage;
  float _bullet_speed;

public:
  // Constructor
  Weapon() = default;

  Weapon(float size_x, float size_y, float pos_x, float pos_y, float bullet_speed, float rate_of_fire, float damage) : GameEntity(size_x, size_y, pos_x, pos_y),
                                                                                                                                                                                                      _bullet_speed(bullet_speed),
                                                                                                                                                                                                      _rate_of_fire(rate_of_fire),
                                                                                                                                                                                                      _damage(damage) {}

  // Copy
  Weapon(const myClass& weapon) : _rate_of_fire(weapon._rate_of_fire) ,
                                                                _damage(weapon._damage),
                                                                _bullet_speed(weapon._bullet_speed)  {}
  myClass& operator=(const myClass&) = default;

  // Move
  Weapon(myClass&&) = default;
  myClass& operator=(myClass&&) = default;

  // Methods
  std::vector<Bullet> shoot(std::vector<Bullet>, bool);

  // Setters

  // Getters
  const float& getRateOfFire() const;

  // Destructor
  ~Weapon() = default;
};
#endif