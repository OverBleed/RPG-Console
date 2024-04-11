#include <iostream>
#include <string>
#include "../include/characters.h"
#include "../include/weapon.h"

using namespace std;

// compile and run on windows (VS Code) : g++ -c src/*cpp -std=c++14 -Wall -g -m64 ; g++ *.o -o bin/debug/main ; ./bin/debug/main
// compile and run on linux : g++ -c src/*cpp -std=c++14 -Wall -g -m64 && g++ *.o -o bin/debug/main && ./bin/debug/main


Character player;
Weapon playerWeapon;
int maxHealth(100), maxMana(100);

void clearScreen() {
	cout << "\033[2J\033[1;1H";
}

string coloredText(string text, string color) {
	string result;
	if (color == "green") result = "\033[32m" + text + "\033[0m";
	if (color == "red") result = "\033[31m" + text + "\033[0m";
	if (color == "blue") result = "\033[34m" + text + "\033[0m";
	return result;
}

Character characterSelection(Character &player) {
	clearScreen();
	string name;
	int choice = 1;
	cout << "What is your name? ";
	cin >> name;
	clearScreen();
	cout << "What is your class?\n[" 
	<< coloredText("1", "green") << "] Swordsman\n["
	<< coloredText("2", "green") << "] Mage\n["
	<< coloredText("3", "green") << "] Tank" << endl;
	cin >> choice;

	switch (choice) {
		case 1:
			player.createCharacter(name, 100, 100);
			break;

		case 2:
			player.createCharacter(name, 80, 120);
			maxHealth = 80;
			maxMana = 120;
			break;

		case 3:
			player.createCharacter(name, 120, 80);
			maxHealth = 120;
			maxMana = 80;
			break;

		default:
			player.createCharacter(name, 100, 100);
			break;
	}
	return player;
}

int main() {
	characterSelection(player);
	player.showStats();
}