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
	<< "HP : " << coloredText1(std::to_string(m_health), "red") << " / " << coloredText1(std::to_string(m_maxHealth), "red") << std::endl
	<< "Mana : " << coloredText1(std::to_string(m_mana), "blue") << " / " << coloredText1(std::to_string(m_maxMana), "blue") << std::endl
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

// constructors

Character::Character() {
	m_level = 1;
	m_exp = 0;
	m_name = "";
}