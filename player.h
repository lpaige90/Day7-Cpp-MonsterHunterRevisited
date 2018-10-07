#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
	std::string playerName;
	int playerHealth;

	public:
		Player(std::string name, int health);//Constructor for creating completely custom player
		Player(std::string name);//Constructor for creating player with custom name
		Player();//Default constructor

		std::string get_name();//Returns player name
		int get_health();//Returns player health
};

#endif