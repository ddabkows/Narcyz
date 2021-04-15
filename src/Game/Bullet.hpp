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

    bool _going_right;

  public:
    // Constructor
    Bullet() = default;

    Bullet(float size_x, float size_y, float pos_x, float pos_y, float move_distance, bool going_right) : GameEntity(size_x, size_y, pos_x, pos_y),
                                                                                                                                                                              _MOVE_DISTANCE(move_distance),
                                                                                                                                                                              _going_right(going_right) {}
    
    // Copy
    Bullet(const myClass& bullet) : _MOVE_DISTANCE(bullet._MOVE_DISTANCE),
                                                            _going_right(bullet._going_right) {}
    myClass& operator=(const myClass&) = delete;

    // Move
    Bullet(myClass&& bullet) {
      _MOVE_DISTANCE = bullet._MOVE_DISTANCE;
      _going_right = bullet._going_right;
    }
    myClass& operator=(myClass&&) = delete;

    //Methods

    // Setters

    // Getters
    const float& getMoveDistance() const;

    // Destructor
    ~Bullet() = default;

};
#endif