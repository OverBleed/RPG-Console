#include <string>
#include "../include/weapon.h"

std::string Weapon::getWeaponName() const{
	return m_name;
}

std::string Weapon::getWeaponDescription() const{
	return m_description;
}

int Weapon::getWeaponDamage(){
	return m_damage;
}

void Weapon::changeWeapon(std::string name, std::string description, int damage) {
	m_name = name;
	m_description = description;
	m_damage = damage;
}

// constructors

Weapon::Weapon() {
	m_name = "Rusty sword";
	m_description = "desc";
	m_damage = 10;
}

Weapon::Weapon(std::string name, std::string description, int damage) {
	m_name = name;
	m_description = description;
	m_damage = damage;
}