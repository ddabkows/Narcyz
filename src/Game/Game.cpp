/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game methods
*/


#include "Game.hpp"


// Methods


// Setters


// Getters
const GameBoard& Game::getBoard() const {return _gameboard;}
const GameEntity& Game::getPlayer() const {return _player;}