/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for GameWindow
*/


#include "Rectangle.hpp"
#include "Master.hpp"
#include "../Game/Dimensions.hpp"
#include <memory>


#ifndef _GAME_WINDOW_H_
#define _GAME_WINDOW_H_


class GameWindow {
  private:
    // Trait
    using myClass = GameWindow;

    Rectangle _background;
    Rectangle _player;
    bool _move_right = false;
    bool _move_left = false;
    bool _close_window = false;

  public:
    // Constructor
    GameWindow(float player_size_x, float player_size_y, float player_pos_x, float player_pos_y) : 
      _background(800.f, 600.f, 0.f, 0.f, sf::Color(0, 0, 0, 255), sf::Color(0, 0, 0, 255), 0.f, 0.f),
      _player(player_size_x, player_size_y, player_pos_x, player_pos_y, sf::Color(255, 255, 255, 255), sf::Color(255, 255, 255, 255), 0.f, 0.f) {}

    // Copy
    GameWindow(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameWindow(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void drawWindow(Master);
    void processEvent(sf::Event);

    // Setters
    void setPlayerPosition(const Dimensions&);

    // Getters
    const bool& getMoveLeft() const;
    const bool& getMoveRight() const;
    const bool& getCloseWindow() const;

    // Destructor
    ~GameWindow() = default;
};
#endif