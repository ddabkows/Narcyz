/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Client main cpp
*/


#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../Game/GameBoard.hpp"
#include "../Game/Dimensions.hpp"
#include "../Game/Game.hpp"
#include "../GUI/Master.hpp"
#include "../GUI/GameWindow.hpp"


int main() {
  Game game;
  Master master_gui;
  GameWindow game_win(game.getPlayerSize().x, game.getPlayerSize().y, game.getPlayerPosition().x, game.getPlayerPosition().y);
  bool keepProgramOpen = true;
  int game_win_output;
  while (keepProgramOpen) {
    sf::Event event;

    while(master_gui.pollEvent(event)) {
      game_win_output = game_win.processEvent(event);
    }

    switch (game_win_output) {
      case 0 : {
        master_gui.closeWindow();
        break;
      }
      case 1 : {
        game.movePlayerHorizontal(1);
        break;
      }
      case 2 : {
        game.movePlayerHorizontal(-1);
        break;
      }
      default : {
        break;
      }
    }

    master_gui.clearWindow();
    game_win.drawWindow(master_gui);
    master_gui.displayWindow();

    if (!master_gui.getOpen()) {
      keepProgramOpen = false;
    }
  }
  return 0;
}