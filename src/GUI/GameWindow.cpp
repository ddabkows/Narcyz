/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameWindow methods
*/


#include "GameWindow.hpp"
#include <iostream>


// Methods
void GameWindow::drawWindow(Master master) {
  master.drawRectangle(_background.getRectangle());
  master.drawRectangle(_player.getRectangle());
}

void GameWindow::processEvent(sf::Event user_event) {

  switch (user_event.type) {
    case sf::Event::Closed : {
      _close_window = true;
      break;
    }
    case sf::Event::KeyPressed : {
      if (user_event.key.code == 3) {
        _move_right = true;
        break;
      }
      else if (user_event.key.code == 0) {
        _move_left = true;
        break;
      }
      break;
    }
    default : {
      break;
    }
  }
}


// Setters
void GameWindow::setPlayerPosition(const Dimensions& pos_to_set) {
  _player.setPosition(pos_to_set.x, pos_to_set.y);
}


// Getters
const bool& GameWindow::getCloseWindow() const {return _close_window;}
const bool& GameWindow::getMoveLeft() const {return _move_left;}
const bool& GameWindow::getMoveRight() const {return _move_right;}