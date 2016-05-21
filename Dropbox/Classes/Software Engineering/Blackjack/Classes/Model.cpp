// copyright 2016
#include <string>
#include <iostream>
#include "Model.hpp"

Model::Model() {
  // vDeck_ = new Deck;
  // vModelDeck_.showDeck();
  theDisplay = NULL;
  vModelDeck_.shuffle();
  vModelDeck_.showDeck();
}

void Model::createPlayers(std::string *name, int count, Display &thisDisplay) {
  Card newCard;
  theDisplay = &thisDisplay;
  for (int i = 0; i < count; i++) {  // deals one card to each player
    newCard = vModelDeck_.getFront();
    std::cout << std::endl << vModelDeck_.getFront().value_
              << " suit"   << vModelDeck_.getFront().suit_ << std::endl;

    players_[i].name_ = name[i];
    players_[i].vHand_.push_back(newCard);
    vModelDeck_.deleteFront();
  }
  /*
  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();

  newCard = vModelDeck_.getFront();
  players_[1].vHand_.push_back(newCard);
  vModelDeck_.deleteFront();
  */
  thisDisplay.setPlayersCount(players_, count);
}

void Model::hit(int theTurn) {
	Card newCard = vModelDeck_.getFront();
	players_[theTurn].vHand_.push_back(newCard);
	vModelDeck_.deleteFront();
  //theDisplay->displayHand();
}
/*
int total_cards(Card* hand,int number_in_Hand)
{
  int i = 0;
  int total = 0;
  for(i=0;i < number_in_Hand;i++)
  {
    switch (hand[i].val)
    {
    case Ace:
      if(total+=11 > 21)
        total+=1;
      else
        total+=11;
      break;
    case Two:
      total+=2;
      break;
    case Three:
      total+=3;
      break;
    case Four:
      total+=4;
      break;
    case Five:
      total+=5;
      break;
    case Six:
      total+=6;
      break;
    case Seven:
      total+=7;
      break;
    case Eight:
      total+=8;
      break;
    case Nine:
      total+=9;
      break;
    case Ten:
      total+=10;
      break;
    case Jack:
      total+=10;
      break;
    case Queen:
      total+=10;
      break;
    case King:
      total+=10;
      break;
    }
  }
  return total;
}
*/
