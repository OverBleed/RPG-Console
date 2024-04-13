#include <iostream>
#include <string>
#include <conio.h>
#include "../include/characters.h"
#include "../include/weapon.h"

using namespace std;


// compile and run on windows (VS Code) : g++ -c src/*cpp -std=c++14 -Wall -g -m64 ; g++ *.o -o bin/debug/main ; ./bin/debug/main
// compile and run on linux : g++ -c src/*cpp -std=c++14 -Wall -g -m64 && g++ *.o -o bin/debug/main && ./bin/debug/main
// g++ -c src/*cpp -std=c++14 -O3 -g -m64 ; g++ *.o -o bin/release/main ; ./bin/release/main


Character player;
Weapon playerWeapon;

Character generalEnemy; // general means it will change based on what enemy the player is fighting
Weapon generalEnemyWeapon;
int signed enemyExpDrop;


void clearScreen() {
	cout << "\033[2J\033[1;1H";
}


void battleScreen(Character &player, Character &enemy) {
	enemy.showStats();
	cout << "\n<===================>\n" << endl;
	player.showStats();
}

// add armor when it is added
void displayInventory(Character &character, Weapon &weapon) {
	clearScreen();
	character.showStats();
	cout << endl;
	weapon.displayWeaponStats();
	cout << endl << "[" << coloredText("ENTER", "green") << "]" << endl;
	getch();
	clearScreen();
}

Character enemyGeneration(Character &enemy, int enemyType) {
	switch (enemyType) {
	case 1: // goblin
		enemy.createCharacter("Goblin", 100, 100, 1);
		enemyExpDrop = 25;
		break;
	
	case 2: // red goblin
		enemy.createCharacter("Red goblin", 130, 120, 1);
		enemyExpDrop = 40;
		break;

	case 3:
		enemy.createCharacter("Squeleton", 150, 150, 1);
		enemyExpDrop = 60;
		break;
	
	default:
		enemy.createCharacter("???", 999999, 999999, 1);
		break;
	}

	return enemy;
	
}

void battle(Character &player, Character &enemy, Weapon &p_weapon, Weapon &e_weapon) {
	bool quit = false;

	do {
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
				cout << "Feature not implemented yet..." << " [" << coloredText("ENTER", "green") << "]" << endl;
				getch();
				break;
		}

		clearScreen();

		if (enemy.isAlive() == false) {
			quit = true;
			cout << coloredText("You won!", "green") << endl;
			player.giveExperience(enemyExpDrop);
			player.levelUp();
		} else if (player.isAlive() == false) {
			quit = true;
			cout << coloredText("You died...", "red") << endl;
		}

	} while (quit == false);

	getch();
	clearScreen();
}

// the menu that the player will have access to whenever not in a fight

void menu() {
	int choice;
	bool inMenu = true;

	do {
		cout << "What will you do?\n[" 
		<< coloredText("1", "green") << "] Stats / Inventory\n["
		<< coloredText("2", "green") << "] Fight monsters in area\n["
		<< coloredText("3", "green") << "] Travel\n["
		<< coloredText("4", "green") << "] Visit shop" << endl;
		cin >> choice;
		clearScreen();

		switch (choice)
		{
			case 1:
				displayInventory(player, playerWeapon);
				break;
			
			case 2:
				enemyGeneration(generalEnemy, 1);
				player.restoreStats();
				generalEnemy.restoreStats();
				cout << "A wild " << coloredText(generalEnemy.getName(), "red") << " has appeared!" << endl;
				getch();
				clearScreen();

				battle(player, generalEnemy, playerWeapon, generalEnemyWeapon);
				break;

			case 3:
				cout << "Feature not implemented yet... [" << coloredText("ENTER", "green") << "]" << endl;
				getch();
				clearScreen();
				break;

			case 4:
				cout << "Feature not implemented yet... [" << coloredText("ENTER", "green") << "]" << endl;
				clearScreen();
				getch();
				break;

			
			default:
				break;
		}
	} while (inMenu == true);
}

Character characterCreation(Character &player) {
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
			player.createCharacter(name, 100, 100, choice);
			break;

		case 2:
			player.createCharacter(name, 80, 120, choice);
			break;

		case 3:
			player.createCharacter(name, 120, 80, choice);
			break;

		default:
			player.createCharacter(name, 100, 100, choice);
			break;
	}
	return player;
}

int main() {
	characterCreation(player);
	player.restoreStats();
	menu();
}