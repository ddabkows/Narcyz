/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for player sprite
*/


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Sprite.hpp"


#ifndef _PLAYER_SPRITE_H_
#define _PLAYER_SPRITE_H_


class PlayerSprite : public Sprite {
  private:
  // Traite
    using myClass = Sprite;

    std::shared_ptr<sf::Texture> _falling_texture;

  public:
  // Constructor
    PlayerSprite(float size_x, float size_y, float pos_x, float pos_y, sf::Color inside_color, float rotation, std::shared_ptr<sf::Texture> texture, std::shared_ptr <sf::Texture> falling_texture) :
      Sprite(size_x, size_y, pos_x, pos_y, inside_color, rotation, texture),
      _falling_texture(falling_texture) {}
    // Copy
    PlayerSprite(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    PlayerSprite(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void setWalkingTexture();
    void setFallingTexture();

    // Setters

    // Getters

    //Destructor
    ~PlayerSprite() = default;
};
#endif