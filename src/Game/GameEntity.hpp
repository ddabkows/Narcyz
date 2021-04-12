/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game Entity - most virtual class
*/


#include "Dimensions.hpp"


#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

class GameEntity {
  private:
    // Trait
    using myClass = GameEntity;
    Dimensions _position;
    Dimensions _size;

  public:
    // Constructor
    GameEntity(int size_x, int size_y, int pos_x, int pos_y) : _position(),
                                                               _size() {
      
    }

    // Copy
    GameEntity(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameEntity(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void horizontalMove(int);

    // Setters
    void setSize(int, int);
    void setPosition(int, int);

    // Getters
    const Dimensions& getSize() const;
    const Dimensions& getPosition() const;
};
#endif