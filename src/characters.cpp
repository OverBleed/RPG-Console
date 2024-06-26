#include <string>
#include <iostream>
#include <fstream>
#include "../include/characters.h"


std::string coloredText(std::string text, std::string color) {
	std::string result;

	if (color == "green") result = "\033[32m" + text + "\033[0m";
	if (color == "red") result = "\033[31m" + text + "\033[0m";
	if (color == "blue") result = "\033[34m" + text + "\033[0m";
	return result;
}

void Character::receiveDamage(int damage) {
	m_health -= damage;

	if (m_health < 0) {
		m_health = 0;
	} else if (m_health > m_maxHealth) {
		m_health = m_maxHealth;
	}
}

void Character::useSpell(int mana) {
	m_mana -= mana;

	if (m_mana < 0) {
		m_mana = 0;
	} else if (m_mana > m_maxMana) {
		m_mana = m_maxMana;
	}
}

void Character::attack(Character &target, int damage) {
	target.receiveDamage(damage);
}

bool Character::isAlive() const{
	if (m_health > 0) {
		return true;
	} else {
		return false;
	}
}

int Character::getLifeLeft() const{
	return m_health;
}

std::string Character::getName() const{
	return m_name;
}

int Character::getMaxHealth() const {
	return m_maxHealth;
}

int Character::getMaxMana() const {
	return m_maxMana;
}

// also changes base stats
void Character::createCharacter(std::string name, int health, int mana, int playerClass) {
	m_name = name;
	m_maxHealth = health;
	m_maxMana = mana;

	switch (playerClass)
	{
		case 1:
			m_baseHealth = health;
			m_baseMana = mana;
			break;

		case 2:
			m_baseHealth = health;
			m_baseMana = mana;
			break;

		case 3:
			m_baseHealth = health;
			m_baseMana = mana;
			break;
		
		default:
			m_baseHealth = health;
			m_baseMana = mana;
			break;
	}
}

void Character::showStats() {
	std::cout << m_name << std::endl
	<< "HP : " << coloredText(std::to_string(m_health), "red") << " / " << coloredText(std::to_string(m_maxHealth), "red") << std::endl
	<< "Mana : " << coloredText(std::to_string(m_mana), "blue") << " / " << coloredText(std::to_string(m_maxMana), "blue") << std::endl
	<< "Lvl : " << m_level << std::endl
	<< "Exp : " << m_exp << std::endl;
}

void Character::restoreStats() {
	m_health = m_maxHealth;
	m_mana = m_maxMana;
}

void Character::giveExperience(int exp) {
	m_exp += exp;
}

void Character::levelUp() {
	int oldLevel = m_level;
	m_level = floor(sqrt(m_exp/60 + 1));
	if (oldLevel != m_level) {
		m_maxHealth = floor(m_baseHealth * pow(1.09, m_level));
		m_maxMana = floor(m_baseMana * pow(1.09, m_level));
	}
}

void Character::loadFile() {
	std::ifstream saveFile("save.txt");
	char readChar;
	std::string readStr = "";
	bool isString = true;
	int count = 0;

	while (saveFile.get(readChar)) {
		if (isString == true) {
			readStr += readChar;
			if (readChar == '\n') {
				m_name = readStr;
				readStr = "";
				isString = false;
			}
		}
		if (isString == false) {
			readStr += readChar;

			if (readStr == "\n") {
				readStr = "";
			}
			if (readChar == '\n' && readStr != "\n" && readStr != "") {
				switch (count)
				{
					case 0:
						m_maxHealth = stoi(readStr);
						count++;
						break;
					
					case 1:
						m_maxMana = stoi(readStr);
						count++;
						break;

					case 2:
						m_baseHealth = stoi(readStr);
						count++;
						break;
					
					case 3:
						m_baseMana = stoi(readStr);
						count++;
						break;

					case 4:
						m_exp = stoi(readStr);
						count++;
						break;

					default:
						break;
				}
				readStr = "";
			}
		}
	}
	saveFile.close();
}

void Character::saveFile() {
	remove("save.txt");
	std::ofstream saveFile("save.txt");
	std::string writeStr = "";
	
	saveFile << m_name << std::endl
	<< m_maxHealth << std::endl
	<< m_maxMana << std::endl
	<< m_baseHealth << std::endl
	<< m_baseMana << std::endl
	<< m_exp << std::endl;

	saveFile.close();
}

// constructors

Character::Character() {
	m_level = 1;
	m_exp = 0;
	m_name = "";
}