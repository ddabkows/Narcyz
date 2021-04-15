/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Client main cpp
*/


#include "Client.hpp"


int main() {
  Game game;
  Master master_gui;
  // 10.f and 30.f being the size of the player.png
  GameWindow game_win(game.getPlayerSize().x / 20.f, game.getPlayerSize().y / 60.f,
                                               game.getPlayerPosition().x, game.getPlayerPosition().y, master_gui.getPlayerTexture(), master_gui.getPlayerFallingTexture(),
                                               master_gui.getPlayerWalkingTexture());
  bool keepProgramOpen = true;
  sf::Clock game_clock;

  while (keepProgramOpen) {
    sf::Event event;

    while(master_gui.getWindow()->pollEvent(event)) {game_win.processEvent(event);}
    concludeEvents(&game_win, &master_gui, &game, game_clock);
    updateWindow(&game_win, &master_gui, &game);

    if (!master_gui.getOpen()) {
      keepProgramOpen = false;
    }
  }
  return 0;
}