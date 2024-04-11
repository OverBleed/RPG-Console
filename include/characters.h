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
	void showStats();
	void restoreStats(); // resets mana and health to their max

	private:

	// rarely change
	std::string m_name;
	int m_level;
	int m_maxHealth;
	int m_maxMana;

	// often change
	int m_health;
	int m_mana;
	int m_exp;
};

#endif