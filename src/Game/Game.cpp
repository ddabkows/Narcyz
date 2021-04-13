/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game methods
*/


#include "Game.hpp"
#include <iostream>


// Methods
void Game::movePlayerHorizontal(float move_x, float time_elapsed) {
  if (time_elapsed - _game_move_clock > 0.02) {
    float move_direction = _MOVE_DISTANCE;
    if (move_x < 0) {
      move_direction = -move_direction;
    }
    if ((move_direction < 0 && 0 < getPlayerPosition().x) || (move_direction > 0 && getPlayerPosition().x + getPlayerSize().x < getBoardSize().x)) {
      _player.horizontalMove(move_direction);
    }
    else {
      std::cout << "Bounds encountered" << std::endl;
    }
    _game_move_clock = time_elapsed;
  }
}


// Setters


// Getters
const GameBoard& Game::getBoard() const {return _gameboard;}
const GameEntity& Game::getPlayer() const {return _player;}
const Dimensions& Game::getBoardSize() const {return _gameboard.getSize();}
const Dimensions& Game::getPlayerSize() const {return _player.getSize();}
const Dimensions& Game::getPlayerPosition() const {return _player.getPosition();}
