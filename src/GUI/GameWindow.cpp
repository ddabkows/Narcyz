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

std::string GameWindow::processEvent(sf::Event user_event) {
  std::string user_event_result;

  switch (user_event.type) {
    case sf::Event::Closed : {
      user_event_result = "close window";
      break;
    }
    case sf::Event::KeyPressed : {
      if (user_event.key.code == 3) {
        user_event_result = "move right";
        break;
      }
      else if (user_event.key.code == 0) {
        user_event_result = "move left";
        break;
      }
      else {
        user_event_result = "do nothing";
        break;
      }
      break;
    }
    default : {
      user_event_result = "do nothing";
      break;
    }
  }
  
  return user_event_result;
}
