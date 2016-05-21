#include "Controller.hpp"

Controller::Controller() {

}

void Controller::passInfo(std::string *name,int count, Display &thisDisplay) {
	theModel_.createPlayers(name, count, thisDisplay);
}

void Controller::checkEvent(sf::RenderWindow &window) {
	sf::Event newEvent;
	static int turn;
	while(window.pollEvent(newEvent)) {

	if (newEvent.type == sf::Event::Closed)
		window.close();

	/*if (event.type == sf::Event::MouseMoved) {
		std::cout << "x: "  << sf::Mouse::getPosition(window).x
							<< " y: " << sf::Mouse::getPosition(window).y << std::endl;
	}*/

	if (newEvent.type == sf::Event::MouseButtonPressed) {
		if ((sf::Mouse::getPosition(window).x > 25)
		&& (sf::Mouse::getPosition(window).x < 75)
		&& (sf::Mouse::getPosition(window).y > 50)
		&& (sf::Mouse::getPosition(window).y < 115)) {
				std::cout << "hit" << "turn: " << turn << std::endl;
				theModel_.hit(turn);
		}


		if ((sf::Mouse::getPosition(window).x > 80)
		&& (sf::Mouse::getPosition(window).x < 150)
		&& (sf::Mouse::getPosition(window).y > 50)
		&& (sf::Mouse::getPosition(window).y < 115)){
			std::cout << "stay";
			turn++;

		}
	}
 }
}
