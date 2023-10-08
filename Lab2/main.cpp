/*
Marc Baldwin & Miles Kent
Lab 2
Program that uses class Pokemon to simulate a basic pokemon battle
*/

#include "pokemon.hpp"
#include <iostream>
using namespace std;


int main() {

	Pokemon attacker("Squirtle", "water", 100, 24, 50);
	attacker.displayStats();

	Pokemon target;
	target.displayStats();

	while (attacker.getHP() > 0 && target.getHP() > 0) {
		// Perform moves and update HP for both attacker and target
		attacker.performMove(target, attacker.getVector());
		target.performMove(attacker, target.getVector());

		// Display updated stats after each round
		attacker.displayStats();
		target.displayStats();
	}

	if (attacker.getHP() <= 0) {
		cout << attacker.getName() << " has fainted. " << target.getName() << " wins!" << endl;
	}
	else {
		cout << target.getName() << " has fainted. " << attacker.getName() << " wins!" << endl;
	}

	return 0;
}