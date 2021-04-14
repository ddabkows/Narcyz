/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Player
*/


#include <memory>
#include "GameEntity.hpp"
#include "Weapon.hpp"


#ifndef _PLAYER_H_
#define _PLAYER_H_


class Player : public GameEntity {
  private:
    // Traits
    using myClass = Player;

    Weapon _weapon;

    bool _looking_right = true;
    bool _looking_left = false;

public:
  // Constructor
  Player(float size_x, float size_y, float pos_x, float pos_y, Weapon weapon) : GameEntity(size_x, size_y, pos_x, pos_y),
                                                                                                                                                                       _weapon() {}

  // Copy
  Player(const myClass&) = delete;
  myClass& operator=(const myClass&) = delete;

  // Move
  Player(myClass&&) = delete;
  myClass& operator=(myClass&&) = delete;

  // Methods
  void lookRight();
  void lookLeft();

  // Setters

  // Getters

  // Destructor
  ~Player() = default;
};
#endif