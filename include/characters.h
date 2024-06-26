#ifndef DEF_CHARACTERS
#define DEF_CHARACTERS

#include <string>
#include <cmath>
#include <fstream>

class Character
{
	public:

	Character();
	void createCharacter(std::string name, int health, int mana, int playerClass);
	void receiveDamage(int damage); // also used to heal, be using negative value
	void attack(Character &target, int damage);
	void useSpell(int mana); // will just consume mana, or restore it

	void showStats();
	void restoreStats(); // resets mana and health to their max

	void giveExperience(int exp); // used for xp gained by player upon winning fight
	void levelUp(); // check if there is a level up

	void loadFile();
	void saveFile();

	// to see/check stuff
	bool isAlive() const;
	int getLifeLeft() const;
	int getMaxHealth() const;
	int getMaxMana() const;
	std::string getName() const;

	private:

	// rarely change
	std::string m_name;
	int signed m_maxHealth;
	int signed m_maxMana;
	int signed m_baseHealth;
	int signed m_baseMana;

	// often change
	int signed m_health;
	int signed m_mana;
	int signed m_level;
	int signed m_exp;
};

std::string coloredText(std::string text, std::string color);

#endif