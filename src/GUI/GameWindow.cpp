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
  if (_player.getScale().x < 0) {
    _player.setPosition(_player.getX() - _player.getScale().x * 10.f, _player.getY());
  }
  master.drawSprite(_player.getSprite());
}

void GameWindow::processEvent(sf::Event user_event) {
  switch (user_event.type) {
    case sf::Event::Closed : {
      _close_window = true;
      break;
    }
    case sf::Event::KeyReleased : {
      if (user_event.key.code == 3) {
        _move_right = false;
        break;
      }
      else if (user_event.key.code == 0) {
        _move_left = false;
        break;
      }
      else if (user_event.key.code == 57) {
        _jump = false;
        break;
      }
      break;
    }
    case sf::Event::KeyPressed : {
      // std::cout << user_event.key.code << std::endl;                          <- Useful only to detect which key is pressed
      if (user_event.key.code == 3) {
        _move_right = true;
        break;
      }
      else if (user_event.key.code == 0) {
        _move_left = true;
        break;
      }
      else if (user_event.key.code == 57) {
        _jump = true;
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

void GameWindow::setPlayerFallingTexture() {
  _player.setFallingTexture();
}

void GameWindow::setPlayerStandingTexture() {
  _player.setStandingTexture();
}

void GameWindow::setPlayerWalkingTexture() {
  _player.setWalkingTexture();
}

void GameWindow::swapPlayerScaleLeft() {
  if (_player.getScale().x > 0) {
    _player.setScale(-_player.getScale().x, _player.getScale().y);
  }
}

void GameWindow::swapPlayerScaleRight() {
  if (_player.getScale().x < 0) {
    _player.setScale(-_player.getScale().x, _player.getScale().y);
  }
}

void GameWindow::setWalkTimer(float new_time) {
  _walk_timer = new_time;
}


// Getters
const bool& GameWindow::getCloseWindow() const {return _close_window;}
const bool& GameWindow::getMoveLeft() const {return _move_left;}
const bool& GameWindow::getMoveRight() const {return _move_right;}
const bool& GameWindow::getJump() const {return _jump;}
const float& GameWindow::getWalkTimer() const {return _walk_timer;}