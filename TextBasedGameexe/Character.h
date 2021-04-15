#pragma once
#include "Header.h"

class Character
{
	
public:
	Character();

	std::string name, race, sex;
	std::vector<std::string> playerRace;

	int health;
	int totalHealth;
	int maxHealth;
	int heal;
	int raceAttack;

	int level, current_xp, base_xp, xp_to_level, minLevel, maxLevel;



	void characterCreation();
};

class Zombie : public Character
{

	
public:

	Zombie();

	int MonsterHp;
	int MonsterXp;
	int MonsterLevel;

	
	std::vector<std::string> monsterName;
	int currentMonsterNames = 5;
	std::string currentMonster = " ";

	void zombieCreation();
};