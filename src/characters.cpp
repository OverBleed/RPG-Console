#include <string>
#include <iostream>
#include "../include/characters.h"


std::string coloredText1(std::string text, std::string color) {
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

void Character::createCharacter(std::string name, int health, int mana) {
	m_name = name;
	m_maxHealth = health;
	m_maxMana = mana;
}

void Character::showStats() {
	std::cout << m_name << std::endl
	<< "HP : " << coloredText1(std::to_string(m_health), "red") << " / " << coloredText1(std::to_string(m_maxHealth), "red") << std::endl
	<< "Mana : " << coloredText1(std::to_string(m_mana), "blue") << " / " << coloredText1(std::to_string(m_maxMana), "blue") << std::endl
	<< "Lvl : " << m_level << std::endl
	<< "Exp : " << m_exp << std::endl;
}

void Character::restoreStats() {
	m_health = m_health;
	m_mana = m_mana;
}

// constructors

Character::Character() {
	m_level = 1;
	m_exp = 0;
	m_name = "";
}