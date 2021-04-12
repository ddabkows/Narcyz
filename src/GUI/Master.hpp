/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game
*/


#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#ifndef _MASTER_H_
#define _MASTER_H_


class Master {
  private:
    // Trait
    using myClass = Master;

    const int _GAMEBOARD_SIZE_X = 800;
    const int _GAMEBOARD_SIZE_Y = 600;

    std::shared_ptr<sf::RenderWindow> window;
  public:
    // Constructor
    Master() : window() {};

    // Copy
    Master(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Master(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void setupWindow();

    // Setters

    // Getters

    // Destructor
    ~Master() = default;

};
#endif