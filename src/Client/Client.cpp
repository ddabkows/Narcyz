/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Client main cpp
*/


#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "../Game/GameBoard.hpp"
#include "../Game/Dimensions.hpp"
#include "../Game/Game.hpp"
#include "../GUI/Master.hpp"
#include <iostream>


int main() {
  Game game;
  Master master_gui;
  bool keepProgramOpen = true;
  while (keepProgramOpen) {
    sf::Event event;

    while(master_gui.pollEvent(event)) {}

    master_gui.clearWindow();
    master_gui.drawWindow();
    master_gui.displayWindow();

    if (!master_gui.getOpen()) {
      keepProgramOpen = false;
    }
  }
  return 0;
}