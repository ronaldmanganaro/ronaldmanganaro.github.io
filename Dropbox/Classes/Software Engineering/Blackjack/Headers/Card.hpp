#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
using std::cout;
using std::endl; 

class Card
{
public:
	Card();
	Card(int newSuit, int newValue);
	int value_;
	int suit_;
private:
	
};

#endif