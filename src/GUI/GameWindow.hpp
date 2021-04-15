/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for GameWindow
*/


#include <memory>
#include "Rectangle.hpp"
#include "Sprite.hpp"
#include "PlayerSprite.hpp"
#include "Master.hpp"
#include "../Game/Dimensions.hpp"
#include "../Game/Bullet.hpp"


#ifndef _GAME_WINDOW_H_
#define _GAME_WINDOW_H_


class GameWindow {
  private:
    // Trait
    using myClass = GameWindow;

    Rectangle _background;
    PlayerSprite _player;
    std::vector<Rectangle> _bullets;

    float _walk_timer = 0.f;
    float _shoot_timer = 0.f;

    bool _move_right = false;
    bool _move_left = false;
    bool _close_window = false;
    bool _jump = false;
    bool _shoot = false;

  public:
    // Constructor
    GameWindow(float player_size_x, float player_size_y, float player_pos_x, float player_pos_y, 
                              std::shared_ptr<sf::Texture> player_texture, std::shared_ptr<sf::Texture> player_falling_texture, std::shared_ptr<sf::Texture> player_walking_texture) : 
      _background(800.f, 600.f, 0.f, 0.f, sf::Color(120, 120, 120, 120), sf::Color(0, 0, 0, 255), 0.f, 0.f),
      _player(player_size_x, player_size_y, player_pos_x, player_pos_y, sf::Color(255, 255, 255, 255), 0.f, player_texture, player_falling_texture, player_walking_texture),
      _bullets() {}

    // Copy
    GameWindow(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameWindow(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void drawWindow(Master);
    void processEvent(sf::Event);
    void createBullets(std::vector<std::shared_ptr<Bullet>>);

    // Setters
    void setPlayerPosition(const Dimensions&);
    void setPlayerFallingTexture();
    void setPlayerStandingTexture();
    void setPlayerWalkingTexture();
    void swapPlayerScaleLeft();
    void swapPlayerScaleRight();
    void setWalkTimer(float);
    void setShootTimer(float);

    // Getters
    const bool& getMoveLeft() const;
    const bool& getMoveRight() const;
    const bool& getCloseWindow() const;
    const bool& getJump() const;
    const bool& getShoot() const;
    const float& getWalkTimer() const;
    const float& getShootTimer() const;

    // Destructor
    ~GameWindow() = default;
};
#endif