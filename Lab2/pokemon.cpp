#include "pokemon.hpp"

string Pokemon::setType(string tp) {
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

void Pokemon::displayStats() {
  cout << string(10, '-') << endl;
  cout << name << endl;
  cout << "Type: " << type << endl;
  cout << "Health: " << HP << endl;
  cout << "Attack: " << attack << endl;
  cout << "Defence: " << defence << endl;
  cout << string(10, '-') << endl;
	}
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
