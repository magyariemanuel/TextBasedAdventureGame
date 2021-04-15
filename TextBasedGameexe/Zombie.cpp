#include "Zombie.h"
#include "TextBasedGameexe.cpp"


Zombie::Zombie()
{
	monsterName = { "Lurker", "Big Head", "Creeper", "The Dead one", "Angry Z", "Screemer" };

	int MonsterHp = 0, MosnterXp = 0, MonsterLevel = 0;
}

void Zombie::CreateMonster()
{
    
        MonsterHp = 30;

        MonsterLevel = (rand() % 3) + character.level;
        MonsterHp = (rand() % 30) * MonsterLevel;
        MonsterXp = MonsterHp;

        if (MonsterHp == 0)
            CreateMonster();
        if (MonsterLevel == 0)
            CreateMonster();

    
}