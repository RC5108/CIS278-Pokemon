#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include <ctime>
//#include "pokemon.hpp"
using namespace std;

class Move {
	public:
		// Default constructor
		Move() : name("Tackle"), type("Normal"), damage(0) {};
		Move(string nIn, string tIn, int dmg) : name(nIn), type(tIn), damage(dmg){};

		// Accessors
		string getName() { return name; };
		string getType() { return type; };
		int getDamage() { return damage; };

		// Mutators
		void setName(string nm) { name = nm; };
		void setType(string ty) { type = ty; };
		int calculateDamage(int attack, int tDefence);



	private:
		string name;
		string type;
		int damage;
		string targetType;

};

int Move::calculateDamage(int att, int tDef) {
	int moveDmg = getDamage();

	// Damage multipler depending on opponenets type
	double typeEffective = 1.0;

	if (type == "Water") {
		if (targetType == "Fire" || targetType == "Fire/Water") {
			typeEffective = 2.0; // Super effective against Fire
		}
		else if (targetType == "Water") {
			typeEffective = 0.5;
		}
	}
	else if (type == "Grass") {
		if (targetType == "Water" || targetType == "Water/Grass") {
			typeEffective = 2.0; // Super effective against Water
		}
		else if (targetType == "Grass") {
			typeEffective = 0.5; 
		}
	}
	else if (type == "Fire") {
		if (targetType == "Grass" || targetType == "Grass/Fire") {
			typeEffective = 2.0; // Super effective against Grass
		}
		else if (targetType == "Fire") {
			typeEffective = 0.5; 
		}
	}

	int calcDmg = static_cast<int>((moveDmg + att) * typeEffective - tDef);
	return max(calcDmg, 0);

}



#endif MOVE_H
