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
	void setName(string nm) { name = nm; }
	void setVector(vector<Move> nv) { listMoves = nv; }
	void performMove(Pokemon& p, vector<Move> listMoves);
	void receiveDamage(int damage);
	string setType(string tp);
	void buildMoves();
	
  // void method that displays pokemon's current stats to the player
	void displayStats();

private:
	string type;
	string name;
	int HP;
	int attack;
	int defence;
	vector<Move> listMoves;
};


#endif // POKEMON_H
