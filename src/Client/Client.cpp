/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Client main cpp
*/


#include "Client.hpp"


int main() {
  Game game;
  Master master_gui;
  GameWindow game_win(game.getPlayerSize().x, game.getPlayerSize().y, game.getPlayerPosition().x, game.getPlayerPosition().y);
  bool keepProgramOpen = true;
  std::string game_win_output;
  while (keepProgramOpen) {
    sf::Event event;

    while(master_gui.getWindow()->pollEvent(event)) {
      game_win.processEvent(event);
      concludeEvents(&game_win, &master_gui, &game);
    }
    
    updateWindow(&game_win, &master_gui);

    if (!master_gui.getOpen()) {
      keepProgramOpen = false;
    }
  }
  return 0;
}