#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "weapon.h"
#include "monster.h"

int randNumber(int maxRange) {
	return rand() % maxRange;
}

int main() {
	std::string where;
	std::string playerChoice;
	int randRun;
	int remainingMonsterHealth;

	srand (time(NULL));

	Player player;
	Monster monster;
	Weapon weapon;

	//Location
	std::string location [4] = { "the fiery pits of Hell", "an underground ice cave", "a large, abandoned castle", "a mosquito-infested swamp" };
	where = location[monster.get_element()];

	//Game Begins
	std::cout << "You are walking through " << where << " when you stumble upon a " << monster.get_name() << "!" << std::endl;
	std::cout << "\nWhat do you want to do, " << player.get_name() << "? (Enter 0 to attack, 1 to run away in fear) " << std::endl;

	std::cin >> playerChoice;

	if( playerChoice == "1" ) {
		randRun = randNumber(2);

		if ( randRun == 0 ) {
			std::cout << "\nThe monster tries to attack you, but you manage to escape! For now..." << std::endl;
		} else {
			std::cout << "\nAs you turn to run away, the monster attacks and kills you.\nGame over, man! Game over!" << std::endl;
		}
	} else if ( playerChoice == "0" ) {
		std::cout << "\nYou look down and notice a pile of weapons lying nearby. With no time to spare, you leap toward the weapons and manage to grab a " << weapon.get_name() << "!" << std::endl;
		std::cout << "Quickly! Make your attack! (Enter any character) " << std::endl;

		std::cin >> playerChoice;

		monster.set_health(monster.get_health() - weapon.get_power());
		remainingMonsterHealth = monster.get_health();

		if ( remainingMonsterHealth <= 0 ) {
			std::cout << "\nYou did it, " << player.get_name() << "! You defeated the " + monster.get_name() + "!";
		} else {
			while ( remainingMonsterHealth > 0 ) {
				std::cout << "\nYour attack has weakened the monster, but it isn't dead yet. What do you want to do? (Enter 0 to attack, 1 to run away in fear) " << std::endl;
				std::cin >> playerChoice;

				if ( playerChoice == "1" ) {
					randRun = randNumber(2);

					if ( randRun == 0 ) {
						std::cout << "\nThe monster tries to attack you, but you manage to escape! For now..." << std::endl;
						break;
					} else {
						std::cout << "\nAs you turn to run away, the monster attacks and kills you.\nGame over, man! Game over!" << std::endl;
						break;
					}
				} else if ( playerChoice == "0" ) {
					monster.set_health(monster.get_health() - weapon.get_power());
					remainingMonsterHealth = monster.get_health();

					if ( remainingMonsterHealth <= 0 ) {
						std::cout << "\nYou did it, " << player.get_name() << "! You defeated the " + monster.get_name() + "!";
					}

				} else {
					std::cout << "\nYour indecision has cost you your life. Game over.";
					break;
				}
			}
		}

	} else {
		std::cout << "\nYour indecision has cost you your life. Game over.";
	}

	return 0;
}