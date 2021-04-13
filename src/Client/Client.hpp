/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Client functions
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


#ifndef _CLIENT_H_
#define _CLIENT_H_


void concludeEvents(GameWindow* game_win, Master* master_gui, Game* game, sf::Clock game_clock) {
  float elapsed_time = game_clock.getElapsedTime().asSeconds();

  if (game_win->getCloseWindow()) {
    master_gui->closeWindow();
  }
  else if (game_win->getMoveLeft()) {
    game->movePlayerHorizontal(-1, elapsed_time);
    game_win->setPlayerPosition(game->getPlayerPosition());
  }
  else if (game_win->getMoveRight()) {
    game->movePlayerHorizontal(1, elapsed_time);
    game_win->setPlayerPosition(game->getPlayerPosition());
  }
  if (!game->getCanJump()) {
    game->setVerticalPosition(elapsed_time);
    std::cout << game->getPlayerPosition().y << std::endl;
    if (game->getPlayerPosition().y > game->getBoardSize().y - game->getPlayerSize().y) {
      game->putPlayerToGround();
      game->setIfCanJump();
    }
  }
  else if (game_win->getJump()) {
    game->setIfCanJump();
    if (game->getCanJump()) {
      game->setJumpMoment(elapsed_time);
    }
  }
}

void updateWindow(GameWindow* game_win, Master* master_gui) {
  master_gui->clearWindow();
  game_win->drawWindow(*master_gui);
  master_gui->displayWindow();
}
#endif