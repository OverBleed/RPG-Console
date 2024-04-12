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

	void giveExperience(int exp); // used for xp gained by player upon winning fight
	void levelUp(); // check if there is a level up

	// to see/check stuff
	bool isAlive() const;
	int getLifeLeft() const;
	std::string getName() const;

	private:

	// rarely change
	std::string m_name;
	int signed m_level;
	int signed m_maxHealth;
	int signed m_maxMana;
	int signed m_baseHealth;
	int signed m_baseMana;

	// often change
	int signed m_health;
	int signed m_mana;
	int signed m_exp;
};

#endif