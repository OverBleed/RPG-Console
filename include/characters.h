#ifndef DEF_CHARACTERS
#define DEF_CHARACTERS

#include <string>

class Character
{
	public:

	Character();
	void createCharacter(std::string name, int health, int mana);
	void receiveDamage(int damage);
	void attack(Character &target, int damage);
	bool isAlive() const;
	int getLifeLeft() const;
	std::string getName() const;
	void showStats(int maxHealth, int maxMana);

	private:

	std::string m_name;
	int m_health;
	int m_mana;
	int m_level;
	int m_exp;
};

#endif