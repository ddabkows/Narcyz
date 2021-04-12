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
    GameBoard _gameboard;
    GameEntity _player;

  public:
    // Constructor
    Game() : _gameboard(800, 600),
             _player(20, 50, 0, 800-50) {
      
    }

    // Copy
    Game(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Game(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void movePlayerHorizontal(int);

    // Setters

    // Getters
    const GameBoard& getBoard() const;
    const GameEntity& getPlayer() const;
    const Dimensions& getPlayerSize() const;
    const Dimensions& getPlayerPosition() const;

    // Destructor
    ~Game() = default;
};
#endif