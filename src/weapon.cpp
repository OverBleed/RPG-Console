#include <iostream>
#include <string>
#include "../include/weapon.h"

std::string Weapon::getWeaponName() const{
	return m_name;
}

void Weapon::displayWeaponStats(){
	std::cout << "Weapon : " << std::endl;
	std::cout << "\e[1m" << m_name << "\e[0m" << std::endl;
	std::cout << "Damage : \033[31m" << m_damage << "\033[0m" << std::endl;
	std::cout << "\e[3m" << m_description << "\e[0m" << std::endl;
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
	m_description = "A very rusty sword. Be carefull, you could catch tetanus!";
	m_damage = 10;
}

Weapon::Weapon(std::string name, std::string description, int damage) {
	m_name = name;
	m_description = description;
	m_damage = damage;
}