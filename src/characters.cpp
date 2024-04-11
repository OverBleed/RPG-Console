#include <string>
#include <iostream>
#include "../include/characters.h"


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
	m_health = health;
	m_mana = mana;
}

void Character::showStats(int maxHealth, int maxMana) {
	std::cout << "HP : " << maxHealth << std::endl;
	std::cout << "Mana : " << maxMana << std::endl;
	std::cout << "Lvl : " << m_level << std::endl;
	std::cout << "Exp : " << m_exp << std::endl;
}

// constructors

Character::Character() {
	m_level = 1;
	m_exp = 0;
	m_name = "";
	m_health = 0;
	m_mana = 0;
}