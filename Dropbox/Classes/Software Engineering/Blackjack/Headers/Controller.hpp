// copyright 2016
#ifndef  CONTROLLER_HPP
#define CONTROLLER_HPP
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Model.hpp"


class Controller {
 public:
  Controller();
  void passInfo(std::string *name, int playerCount,  Display &thisDisplay);
  //static int turn;
  
  void checkEvent(sf::RenderWindow &window);
 private:
  Model theModel_;

};

#endif
