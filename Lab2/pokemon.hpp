#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "move.hpp"
using namespace std;

class Pokemon {
	
public:
	Pokemon(string nIn, string tIn, int hpIn, int aIn, int dIn) : 
		name(nIn), type(tIn), HP(hpIn), attack(aIn), defence(dIn) {
		buildMoves();
	};

	// Default constructor that assigns the default pokemon to Magikarp
	Pokemon() : name("Magikarp"), type("water"), HP(12), attack(10), defence(20) {
		buildMoves();
	};


	// Accessors
	int getHP() { return HP; };
	int getDefence() { return defence; };
	int getAttack() { return attack; };
	string getType() { return type; };
	string getName() { return name; };
	vector<Move> getVector() {return listMoves;}


	// Mutators
	void setHP(int newHP) { HP = newHP; };
	void setDefence(int ac) { defence = ac; };
	void setAttack(int atk) { attack = atk; };
	string setType(string tp) {
		if (tp == "water" || tp == "Water") {
			type = "Water";
		}
		else if (tp == "fire" || tp == "Fire") {
			type = "Fire";
		}
		else if (tp == "grass" || tp == "Grass") {
			type = "Grass";
		}
		else if (tp == "normal" || tp == "Normal") {
			type = "Normal";
		}
		return type;
	}
	void setName(string nm) { name = nm; }
	void setVector(vector<Move> nv) { listMoves = nv; }

	void performMove(Pokemon& p, vector<Move> listMoves);
	void receiveDamage(int damage);
	void buildMoves();

	// void method that displays pokemon's current stats to the player
	void displayStats() {
		cout << string(10, '-') << endl;
		cout << name << endl;
		cout << "Type: " << type << endl;
		cout << "Health: " << HP << endl;
		cout << "Attack: " << attack << endl;
		cout << "Defence: " << defence << endl;
		cout << string(10, '-') << endl;
	}

	

private:
	string type;
	string name;
	int HP;
	int attack;
	int defence;
	vector<Move> listMoves;
};


void Pokemon::performMove(Pokemon& p, vector<Move> moves) {
 
	int randomMoveIndex = rand() % listMoves.size();
	Move& moveUsed = listMoves[randomMoveIndex];
	int damage = moveUsed.calculateDamage(attack, p.defence);

	p.receiveDamage(damage);

	cout << name << " used " << moveUsed.getName() << "!" << endl;
	cout << name << " dealt " << damage << " damage to " << p.getName() << "!" << endl;
}


// Function to populate listMoves with 1 to 4 random Move objects
void Pokemon::buildMoves() {
	listMoves.clear(); // Clear the existing moves

	// Random number from 1 to 4 to generate the number of moves the Pokemon has
	int numMoves = rand() % 4 + 1;

	// Generate and add random Move objects to the listMoves vector
	for (int i = 0; i < numMoves; i++) {
		Move nextMove;
		listMoves.push_back(nextMove); // Add the Move to the listMoves vector
	}
}

// Function that takes the calculated damage and subtracts it from the Pokemon's HP
void Pokemon::receiveDamage(int dmg) {
	HP -= dmg;

	if (HP < 0) {
		HP = 0;
	}

	cout << name << " has received " << dmg << " damage" << endl;
	cout << name << " is currently at " << HP << " health points!" << endl;

}


#endif POKEMON_H
