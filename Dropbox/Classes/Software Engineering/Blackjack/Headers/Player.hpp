#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Card.hpp"
#include <vector>
class Player
{
public:
	Player();
	Player(std::string name);
	std::string name_;
	std::vector<Card> vHand_; 
protected:
	
	
};
	
#endif