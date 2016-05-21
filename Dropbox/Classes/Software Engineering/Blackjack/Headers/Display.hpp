// copyright 2016
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Player.hpp"
//#include "Controller.hpp"

class Display {
 public:
  Display();
  void drawPlayers();
  void displayHand();
  void drawUI();
  //Controller theController;
  std::string findValue(int value);
  void setPlayersCount(Player *newPlayers, int count);
  sf::Text theName[4];
  int pCount;
  sf::RenderWindow window;
  Player displayPlayers[4];
 private:
  void createWindow( Display &thisDisplay);
  void promptUser( Display &thisDisplay);
};

#endif  // DISPLAY_HPP
