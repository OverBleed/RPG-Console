#include <iostream>
#include <string>
#include "../include/characters.h"
#include "../include/weapon.h"

using namespace std;


// compile and run on windows (VS Code) : g++ -c src/*cpp -std=c++14 -Wall -g -m64 ; g++ *.o -o bin/debug/main ; ./bin/debug/main
// compile and run on linux : g++ -c src/*cpp -std=c++14 -Wall -g -m64 && g++ *.o -o bin/debug/main && ./bin/debug/main
// g++ -c src/*cpp -std=c++14 -O3 -g -m64 ; g++ *.o -o bin/release/main ; ./bin/release/main


Character player;
Weapon playerWeapon;
int maxHealth(100), maxMana(100);

Character generalEnemy; // general means it will change based on what enemy the player is fighting
Weapon generalEnemyWeapon;


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

void battleScreen(Character &player, Character &enemy) {
	enemy.showStats();
	cout << "\n<===================>\n" << endl;
	player.showStats();
}

void battle(Character &player, Character &enemy, Weapon &p_weapon) {
	battleScreen(player, enemy);

	int choice;

	cout << "\nWhat will you do?\n[" 
	<< coloredText("1", "green") << "] Attack\n["
	<< coloredText("2", "green") << "] Use spell\n["
	<< coloredText("3", "green") << "] Use item\n["
	<< coloredText("4", "green") << "] Run away" << endl;
	cin >> choice;

	switch (choice)
	{
		case 1:
			player.attack(enemy, p_weapon.getWeaponDamage());
			break;
		
		default:
			cout << "Feature not implemented yet" << endl;
			break;
	}

	clearScreen();

	if (enemy.isAlive() == false) {
		player.giveExperience(250);
		player.levelUp();
	}
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
	clearScreen();

	
	// class don't change base stats, just weapons and spells

	switch (choice) {
		case 1:
			break;

		case 2:
			player.createCharacter(name, 80, 120, choice);
			maxHealth = 80;
			maxMana = 120;
			break;

		case 3:
			player.createCharacter(name, 120, 80, choice);
			maxHealth = 120;
			maxMana = 80;
			break;

		default:
			player.createCharacter(name, 100, 100, choice);
			break;
	}
	return player;
}


int main() {
	characterSelection(player);
	generalEnemy.createCharacter("goblin", 100, 100, 1);
	generalEnemy.restoreStats();
	player.restoreStats();


	player.giveExperience(250);
	player.levelUp();
	player.showStats();
}