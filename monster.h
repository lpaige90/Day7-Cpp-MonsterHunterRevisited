#ifndef MONSTER_H
#define MONSTER_H
#include <string>

class Monster {
	std::string monsterName;
	int monsterElement;
	int monsterHealth;

	public:
		Monster(std::string name, int element, int health);//Constructor for creating custom monster
		Monster();//Default constructor

		std::string get_name();//Returns monster name
		int get_element();//Returns monster element
		int get_health();//Returns monster health

		void set_health(int health);//Sets monster health
};

#endif