/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Player Sprite methods
*/


#include "PlayerSprite.hpp"


// Methods
void PlayerSprite::setStandingTexture() {
  _sprite.setTexture(*_texture);
}

void PlayerSprite::setFallingTexture() {
  _sprite.setTexture(*_falling_texture);
}

void PlayerSprite::setWalkingTexture() {
  _sprite.setTexture(*_walking_texture);
}