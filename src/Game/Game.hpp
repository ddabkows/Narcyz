/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game
*/


#include <vector>
#include "GameBoard.hpp"
#include "Weapon.hpp"
#include "Player.hpp"
#include "Bullet.hpp"


#ifndef _GAME_H_
#define _GAME_H_

class Game final {
  private:
    //Trait
    using myClass = Game;

    const float _GAMEBOARD_SIZE_X = 800.f;
    const float _GAMEBOARD_SIZE_Y = 600.f;
    const float _PLAYER_SIZE_X = 30.f;
    const float _PLAYER_SIZE_Y = _PLAYER_SIZE_X * 3.f;
    float _game_move_clock = 0.f;
    float _moment_of_jump = 0.f;
    bool _player_can_jump = true;

    GameBoard _gameboard;
    Weapon _simple_weapon;
    Player _player;
    std::vector<std::shared_ptr<Bullet>> _bullets;
    
  public:
    // Constructor
    Game() : _gameboard(_GAMEBOARD_SIZE_X, _GAMEBOARD_SIZE_Y),
                     _simple_weapon(15.f, 5.f, (_GAMEBOARD_SIZE_X - _PLAYER_SIZE_X) / 2 + _PLAYER_SIZE_X - 15.f, (_GAMEBOARD_SIZE_Y - _PLAYER_SIZE_Y) + _PLAYER_SIZE_X, 20.f, 1.f, 1.f),
                     _player(_PLAYER_SIZE_X, _PLAYER_SIZE_Y, (_GAMEBOARD_SIZE_X - _PLAYER_SIZE_X) / 2, (_GAMEBOARD_SIZE_Y - _PLAYER_SIZE_Y), _simple_weapon) {}

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
    void shoot();
    void moveBullets();

    // Setters
    void setJumpMoment(float);

    // Getters
    const GameBoard& getBoard() const;
    const GameEntity& getPlayer() const;
    const Dimensions& getBoardSize() const;
    const Dimensions& getPlayerSize() const;
    const Dimensions& getPlayerPosition() const;
    const bool& getCanJump() const;
    const std::vector<std::shared_ptr<Bullet>>& getBullets() const;
    const float& getPlayerRateOfFire() const;

    // Destructor
    ~Game() = default;
};
#endif