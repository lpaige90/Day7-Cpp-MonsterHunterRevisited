#include "player.h"

//Constructor for creating completely custom player
Player::Player(std::string name, int health) {
	playerName = name;
	playerHealth = health;
}

//Constructor for creating player with custom name
Player::Player(std::string name) {
	playerName = name;
	playerHealth = 300;
}

//Default constructor
Player::Player() {
	playerName = "hero";
	playerHealth = 300;
}

//Returns player name
std::string Player::get_name() {
	return playerName;
}

//Returns player health
int Player::get_health() {
	return playerHealth;
}