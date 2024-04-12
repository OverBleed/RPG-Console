#ifndef DEF_CHARACTERS
#define DEF_CHARACTERS

#include <string>
#include <cmath>

class Character
{
	public:

	Character();
	void createCharacter(std::string name, int health, int mana, int playerClass);
	void receiveDamage(int damage);
	void attack(Character &target, int damage);

	void showStats();
	void restoreStats(); // resets mana and health to their max

	void giveExperience(int exp); // used for both enemy xp drop and xp gained by player upon winning fight
	void levelUp(); // check if there is a level up

	// to see/check stuff
	bool isAlive() const;
	int getLifeLeft() const;
	std::string getName() const;

	private:

	// rarely change
	std::string m_name;
	int m_level;
	int m_maxHealth;
	int m_maxMana;
	int m_baseHealth;
	int m_baseMana;

	// often change
	int m_health;
	int m_mana;
	int m_exp;
};

#endif