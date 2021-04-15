#include "Character.h"


Character::Character()
{

	name = " ";
	race = " ";
	sex = " ";


	playerRace = {"doctor", "engineer", "boxer", "officer", "firefighter"};

    level = 0, health = 0, totalHealth = 0, maxHealth = 0, heal = 0, raceAttack = 0;

    level = 1, current_xp = 0, base_xp = 83, xp_to_level = base_xp, minLevel = 1, maxLevel = 60;

}

Zombie::Zombie()
{
     monsterName = { "Lurker", "Big Head", "Creeper", "The Dead one", "Angry Z", "Screemer" };
}


void Character::characterCreation()
{
    int counter = 0;


    std::cout << "Enter the Characters Name: ";
    std::cin >> name;
    std::cout << "Enter the Characters Race\n";
    std::cout << "Doctor\n";
    std::cout << "Engineer\n";
    std::cout << "Boxer\n";
    std::cout << "Officer\n";
    std::cout << "FireFighter\n";
    std::cout << "Type below your Race: \n\n";
    std::cin >> race;

    std::for_each(race.begin(), race.end(), [](char& c)
        {
            c = ::tolower(c);
        });


    for (int i = 0; 1 < sizeof(playerRace); i++)
    {
        if (race == "doctor")
        {
            health = 100;
            raceAttack = 5 * level;
            break;
        }
        if (race == "engineer")
        {
            health = 120;
            raceAttack = 7 * level;
            break;
        }
        if (race == "boxer")
        {
            health = 150;
            raceAttack = 10 * level / 2 + 2;
            break;
        }
        if (race == "officer")
        {
            health = 110;
            raceAttack = 9 * level;
            break;
        }
        if (race == "fireFighter")
        {
            health = 140;
            raceAttack = 10 * level;
            break;
        }
        else
        {
            std::cout << "Please choose a correct race \n";
            Character::characterCreation();
        }
    }

    std::cout << "\n";
    std::cout << "Enter the Characters Sex: ";
    std::cin >> sex;
    system("cls");

    for (int i = 0; i <= counter; i++)
    {
        if (i == 0)
            std::cout << "Creating Character.\n";
        if (i == 1)
            std::cout << "Creating Character..\n";
        if (i == 2)
        {
            std::cout << "Creating Character...\n";
            break;
        }

        Sleep(1000);
        system("cls");
        counter++;
    }

    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    sex[0] = toupper(sex[0]);

    totalHealth = health;
    maxHealth = totalHealth;
}

 void Zombie::zombieCreation()
{

    MonsterHp = 30;

    MonsterLevel = (rand() % 3) + level;
    MonsterHp = (rand() % 30) * MonsterLevel;
    MonsterXp = MonsterHp;

    if (MonsterHp == 0)
        zombieCreation();
    if (MonsterLevel == 0)
        zombieCreation();


}