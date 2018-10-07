#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
	std::string weaponName;
	int weaponElement;
	int weaponPower;

	public:
		Weapon(std::string name, int element, int power);//Constructor for creating custom weapon
		Weapon();//Default constructor

		std::string get_name();//Returns weapon name
		int get_element();//Returns weapon element
		int get_power();//Returns weapon attack power
};

#endif