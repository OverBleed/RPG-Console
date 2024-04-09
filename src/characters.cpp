#include <string>
#include "characters.h"
#include "weapon.h"


void Character::receiveDamage(int damage) {
	m_health -= damage;

	if (m_health < 0) {
		m_health = 0;
	}
}

void Character::attack(Character &target) {
	// target.receiveDamage(m_weapon().getWeaponDamage());
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

// constructors

Character::Character(std::string name) {
	m_name = name;
	m_health = 100;
	m_mana = 100;
	// m_weapon() = Weapon();
}