/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Bullet
*/


#include "GameEntity.hpp"


#ifndef _BULLET_H_
#define _BULLET_H_


class Bullet : public GameEntity {
  private:
    // Trait
    using myClass = Bullet;

    float _MOVE_DISTANCE;
    float _DAMAGE;

  public:
    // Constructor
    Bullet() = default;

    Bullet(float size_x, float size_y, float pos_x, float pos_y, float move_distance, float damage) : GameEntity(size_x, size_y, pos_x, pos_y),
                                                                                                                                                                              _MOVE_DISTANCE(move_distance),
                                                                                                                                                                              _DAMAGE(damage) {}
    
    // Copy
    Bullet(const myClass& bullet) : _MOVE_DISTANCE(bullet._MOVE_DISTANCE),
                                                           _DAMAGE(bullet._DAMAGE) {}
    myClass& operator=(const myClass&) = delete;

    // Move
    Bullet(myClass&& bullet) : _MOVE_DISTANCE(bullet._MOVE_DISTANCE),
                                                   _DAMAGE(bullet._DAMAGE) {}
    myClass& operator=(myClass&&) = delete;

    //Methods

    // Setters

    // Getters
    const float& getMoveDistance() const;

    // Destructor
    ~Bullet() = default;

};
#endif