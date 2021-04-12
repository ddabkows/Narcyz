/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game methods
*/


#include "Game.hpp"


// Methods
void Game::movePlayerHorizontal(int move_x) {
  _player.horizontalMove(move_x);
}


// Setters


// Getters
const GameBoard& Game::getBoard() const {return _gameboard;}
const GameEntity& Game::getPlayer() const {return _player;}
const Dimensions& Game::getBoardSize() const {return _gameboard.getSize();}
const Dimensions& Game::getPlayerSize() const {return _player.getSize();}
const Dimensions& Game::getPlayerPosition() const {return _player.getPosition();}
