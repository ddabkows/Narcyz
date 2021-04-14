/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game methods
*/


#include "Game.hpp"
#include <iostream>


// Methods
void Game::movePlayerHorizontal(float move_x, float time_elapsed) {
  if (time_elapsed - _game_move_clock > 0.02f) {
    float move_direction = _PLAYER_MOVE_DISTANCE;
    if (move_x < 0) {
      move_direction = -move_direction;
      _player.lookLeft();
    }
    else {
      _player.lookRight();
    }
    if ((move_direction < 0 && 0 < getPlayerPosition().x) || (move_direction > 0 && getPlayerPosition().x + getPlayerSize().x < getBoardSize().x)) {
      _player.horizontalMove(move_direction);
    }
    _game_move_clock = time_elapsed;
  }
}

void Game::setIfCanJump() {
  if (_player.getPosition().y == _gameboard.getSize().y - _player.getSize().y) {
    _player_can_jump = true;
  }
  else {
    _player_can_jump = false;
  }
}

void Game::setVerticalPosition(float moment) {
  float time_elapsed_since_ground = moment - _moment_of_jump;
  float vertical_position_to_set = 20000.f / 18.f  * (getPlayerSize().y / 50.f) * time_elapsed_since_ground * time_elapsed_since_ground - 2000.f / 3.f * (getPlayerSize().y / 50.f) * time_elapsed_since_ground;

  _player.setPosition(_player.getPosition().x, _gameboard.getSize().y - _player.getSize().y + vertical_position_to_set);
}

void Game::putPlayerToGround() {
  _player.setPosition(_player.getPosition().x, _gameboard.getSize().y - _player.getSize().y);
}


// Setters
void Game::setJumpMoment(float moment) {
  _player_can_jump = false;
  _moment_of_jump = moment;
}


// Getters
const GameBoard& Game::getBoard() const {return _gameboard;}
const GameEntity& Game::getPlayer() const {return _player;}
const Dimensions& Game::getBoardSize() const {return _gameboard.getSize();}
const Dimensions& Game::getPlayerSize() const {return _player.getSize();}
const Dimensions& Game::getPlayerPosition() const {return _player.getPosition();}
const bool& Game::getCanJump() const {return _player_can_jump;}
