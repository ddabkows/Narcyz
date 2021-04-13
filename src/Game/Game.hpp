/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game
*/


#include "GameBoard.hpp"
#include "GameEntity.hpp"


#ifndef _GAME_H_
#define _GAME_H_

class Game final {
  private:
    //Trait
    using myClass = Game;

    const float _GAMEBOARD_SIZE_X = 800;
    const float _GAMEBOARD_SIZE_Y = 600;
    const float _PLAYER_SIZE_X = 20;
    const float _PLAYER_SIZE_Y = 50;
    const float _MOVE_DISTANCE = 10;
    float _game_move_clock = 0;
    float _moment_of_jump = 0;
    bool _player_can_jump = true;

    GameBoard _gameboard;
    GameEntity _player;

  public:
    // Constructor
    Game() : _gameboard(_GAMEBOARD_SIZE_X, _GAMEBOARD_SIZE_Y),
             _player(_PLAYER_SIZE_X, _PLAYER_SIZE_Y, (_GAMEBOARD_SIZE_X - _PLAYER_SIZE_X) / 2, (_GAMEBOARD_SIZE_Y - _PLAYER_SIZE_Y)) {}

    // Copy
    Game(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Game(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void movePlayerHorizontal(float, float);
    void setIfCanJump();
    void setVerticalPosition(float);
    void putPlayerToGround();

    // Setters
    void setJumpMoment(float);

    // Getters
    const GameBoard& getBoard() const;
    const GameEntity& getPlayer() const;
    const Dimensions& getBoardSize() const;
    const Dimensions& getPlayerSize() const;
    const Dimensions& getPlayerPosition() const;
    const bool& getCanJump() const;

    // Destructor
    ~Game() = default;
};
#endif