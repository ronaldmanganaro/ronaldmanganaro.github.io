// copyright 2016
#ifndef MODEL_HPP
#define MODEL_HPP
#include <string>
#include "Display.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"

class Model {
 public:
  Model();
  // Card hit();
  //Display mainDisplay;
  void hit(int theTurn);
  void createPlayers(std::string *name, int count, Display &thisDisplay);
 private:
  Display* theDisplay;
  std::string names_[];
  Player players_[4];
  Dealer dealer_;
  Deck vModelDeck_;
};

#endif
