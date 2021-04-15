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


void setContext(GameWindow* game_win, Game* game, sf::Clock game_clock) {
  float elapsed_time = game_clock.getElapsedTime().asSeconds();

  if (!game->getCanJump()) {
    game_win->setPlayerFallingTexture();
    game->setVerticalPosition(elapsed_time);
    if (game->getPlayerPosition().y > game->getBoardSize().y - game->getPlayerSize().y) {
      game->putPlayerToGround();
      game->setIfCanJump();
    }
  }
  else {
    float time_since_last_step = game_clock.getElapsedTime().asSeconds() - game_win->getWalkTimer();

    if (time_since_last_step > 0.6f) {
      game_win->setWalkTimer(game_clock.getElapsedTime().asSeconds());
      game_win->setPlayerStandingTexture();
    }
    else if (time_since_last_step > 0.3f) {
      if (game_win->getMoveLeft() || game_win->getMoveRight()) {
        game_win->setPlayerWalkingTexture();
      }
    }
  }
}

void concludeEvents(GameWindow* game_win, Master* master_gui, Game* game, sf::Clock game_clock) {
  float elapsed_time = game_clock.getElapsedTime().asSeconds();

  if (game_win->getCloseWindow()) {
    master_gui->closeWindow();
  }
  else if (game_win->getMoveLeft()) {
    game->movePlayerHorizontal(-1, elapsed_time);
    game_win->swapPlayerScaleLeft();
  }
  else if (game_win->getMoveRight()) {
    game->movePlayerHorizontal(1, elapsed_time);
    game_win->swapPlayerScaleRight();
  }
  setContext(game_win, game, game_clock);
  if (game_win->getJump()) {
    game->setIfCanJump();
    if (game->getCanJump()) {
      game->setJumpMoment(elapsed_time);
    }
  }
  if (elapsed_time > game_win->getShootTimer()) {
    game->shoot();
    game_win->setShootTimer(elapsed_time);
  }
  game_win->setPlayerPosition(game->getPlayerPosition());
}

void updateWindow(GameWindow* game_win, Master* master_gui) {
  master_gui->clearWindow();
  game_win->drawWindow(*master_gui);
  master_gui->displayWindow();
}
#endif