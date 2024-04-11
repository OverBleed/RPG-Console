#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <string>

class Weapon
{
	public:

	Weapon();
	Weapon(std::string name, std::string description, int damage);
	std::string getWeaponName() const;
	std::string getWeaponDescription() const;
	int getWeaponDamage();
	void changeWeapon(std::string name, std::string description, int damage);

	private:

	std::string m_name;
	std::string m_description;
	int m_damage;
};


#endif