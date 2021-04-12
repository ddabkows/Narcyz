/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Client main cpp
*/


#include "../Game/GameBoard.hpp"
#include "../Game/Dimensions.hpp"
#include "../Game/Game.hpp"
#include <iostream>


int main() {
  Game game;
  bool end_game = false;
  while (!end_game) {
    std::cout << "Board : " << std::endl;
    std::cout << 0 << "--------" << game.getBoardSize().x << std::endl;
    std::cout << "Player : " << std::endl;
    std::cout << "---" << game.getPlayerPosition().x << "---" << std::endl;
    std::cout << "Want to move ?" << std::endl;
    char decision;
    std::cin >> decision;
    std::cout << "\n";
    switch (decision) {
      case 'a' : {
        game.movePlayerHorizontal(-1);
        break;
      }
      case 'd' : {
        game.movePlayerHorizontal(1);
        break;
      }
      case 's' : {
        end_game = true;
        break;
      }
      default : {
        break;
      }
    }
  }
  return 0;
}