/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameWindow methods
*/


#include "GameWindow.hpp"


// Methods
void GameWindow::drawWindow(Master master) {
  master.drawRectangle(_background.getRectangle());
  master.drawRectangle(_player.getRectangle());
}

int GameWindow::processEvent(sf::Event user_event) {
  int user_event_result;

  switch (user_event.type) {
    case sf::Event::Closed : {
      user_event_result = 0;
      break;
    }
    case sf::Event::KeyPressed : {
      if (user_event.key.code == 3) {
        user_event_result = 1;
        break;
      }
      else if (user_event.key.code == 0) {
        user_event_result = 2;
        break;
      }
      break;
    }
    default : {
      user_event_result = 4;
      break;
    }
  }

  return user_event_result;
}