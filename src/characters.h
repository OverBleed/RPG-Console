#ifndef DEF_CHARACTERS
#define DEF_CHARACTERS

#include <string>
#include "weapon.h"

class Character
{
	public:

	Character(std::string name);
	void receiveDamage(int damage);
	void attack(Character &target);
	bool isAlive() const;
	int getLifeLeft() const;
	std::string getName() const;

	private:

	std::string m_name;
	int m_health;
	int m_mana;
	Weapon m_weapon;
};

#endif