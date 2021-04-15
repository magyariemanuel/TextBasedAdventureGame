#pragma once
#include "Header.h"



class Zombie
{

public:
	Zombie();

	int MonsterHp = 0;
	int MonsterXp = 0;
	int MonsterLevel = 0;

	std::vector<std::string> monsterName;
	// std::string monsterName[] = { "Lurker", "Big Head", "Creeper", "The Dead one", "Angry Z", "Screemer" };
	int currentMonsterNames = 5;
	std::string currentMonster = " ";

	void CreateMonster();
};

