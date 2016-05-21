// copyright 2016
#include <string>
#include "Display.hpp"
#include "Controller.hpp"
Controller theController;

Display::Display() {
  window.create(sf::VideoMode(600, 600), "Blackjack");
  createWindow(*this);
}

void Display::createWindow( Display &thisDisplay) {
  static int prompt = 0;
  while (window.isOpen()) {
    // should be in controller

    theController.checkEvent(window);

    window.clear(sf::Color::Black);

    if (prompt == 0) {
      window.clear(sf::Color::Black);
      promptUser(thisDisplay);
      prompt++;
    }

    drawPlayers();
    drawUI();
    window.display();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
      std::cout << "update" << std::endl;
    }
  }
}

void Display::promptUser( Display &thisDisplay) {
  std::system("clear");
  int count;
  sf::Font font;
  font.loadFromFile("Sprites/arial.ttf");
  sf::Text text;

  /* add at end
  text.setString("Please type player count into terminal (1-4) \n");
  text.setFont(font);
  window.draw(text);
  window.display();
  std::cout << "Enter player count: ";
  std::cin >> count;
  text.setPosition(0,30);
  text.setString("Please enter the names for each player\n");
  window.draw(text);
  window.display();
  */
  count = 4;  // temp delete at end
  std::string* name = new std::string[count];

  for (int i = 1; i <= count; i++) {
    /*
    std::cout << "Please enter player " << i << ": " << std::endl;
    std::cin >> name[i-1];
    */
    name[0] = "Ron";
    name[1] = "Chris";
    name[2] = "Laura";
    name[3] = "David";
  }

  theController.passInfo(name, count, thisDisplay);
}

void Display::drawPlayers() {
  sf::Font font;
  if (!font.loadFromFile("Sprites/arial.ttf"))
  std::cout << "font not found" << std::endl;
  for (int i = 0; i < 4; i++) {
    theName[i].setFont(font);
    theName[i].setString(displayPlayers[i].name_);
    theName[i].setPosition((i*150)+35, 0);
    window.draw(theName[i]);
  }

  displayHand();
  // std::cout << players->name_;
  return;
}

void Display::displayHand() {
  int k = 0;
  sf::Texture cardTexture[20];
  sf::Sprite cardSprites[20];
  int x = 0, y = 40;
  std::string temp("Sprites/Cards/");

  for (int i = 0; i < pCount; i++)  // players
    for (int j = 0; j < displayPlayers[i].vHand_.size(); j++) {  // crds in hand
      switch (displayPlayers[i].vHand_[j].suit_) {  // suit
      case 0:
        temp = temp + 'c';
        temp = temp + findValue(displayPlayers[i].vHand_[j].value_);
        temp = temp + ".png";
        break;
      case 1:
        temp = temp + 's';
        temp = temp + findValue(displayPlayers[i].vHand_[j].value_);
        temp = temp + ".png";
        break;
      case 2:
        temp = temp + 'd';
        temp = temp + findValue(displayPlayers[i].vHand_[j].value_);
        temp = temp + ".png";
        break;
      case 3:
        temp = temp + 'h';
        temp = temp + findValue(displayPlayers[i].vHand_[j].value_);
        temp = temp + ".png";
        break;
    }
    if (!cardTexture[k].loadFromFile(temp))
      std::cout << temp;
    // std::cout << k << " " << temp << std::endl;
    cardSprites[k].setPosition(x+(i*150), y+(j*50));
    cardSprites[k].setTexture(cardTexture[k]);
    k++;

    temp = "Sprites/Cards/";
  }
  int total = k;
  for (k = 0; k < total; k++)
    window.draw(cardSprites[k]);
}

std::string Display::findValue(int value) {
  std::string temp;
  switch (value) {
    case 1:
      temp = "01";
      break;
    case 2:
      temp = "02";
      break;
    case 3:
      temp = "03";
      break;
    case 4:
      temp = "04";
      break;
    case 5:
      temp = "05";
      break;
    case 6:
      temp = "06";
      break;
    case 7:
      temp = "07";
      break;
    case 8:
      temp = "08";
      break;
    case 9:
      temp = "09";
      break;
    case 10:
      temp = "10";
      break;
    case 11:
      temp = "11";
      break;
    case 12:
      temp = "12";
      break;
    case 13:
      temp = "13";
      break;
  }

  return temp;
}

void Display::setPlayersCount(Player *players, int count) {
  pCount = count;
  for (int i = 0; i < count; i++) {
    displayPlayers[i] = players[i];
  }
}

void Display::drawUI() {
  sf::Sprite hitBtn, skipBtn;
  sf::Texture hitTexture, skipTexture;

  if (!hitTexture.loadFromFile("Sprites/hit.png"))
    std::cout << "could not find hit.png";
  if (!skipTexture.loadFromFile("Sprites/stay.png"))
    std::cout << "could not find skip.png";
  // sf::IntRect Btn(window.getSize().x/3,window.getSize().y/1.15)

  sf::Vector2u windowSize;
  windowSize = window.getSize();
  hitBtn.setScale(.5, .5);
  skipBtn.setScale(.5, .5);
  hitBtn.setPosition(25, 50);
  skipBtn.setPosition(75, 50);
  hitBtn.setTexture(hitTexture);
  skipBtn.setTexture(skipTexture);
  window.draw(hitBtn);
  window.draw(skipBtn);
}
