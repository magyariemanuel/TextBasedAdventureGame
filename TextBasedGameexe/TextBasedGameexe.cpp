#include "Character.h"


void HUD();
void Combat();
void CombatHUD();
void Moving();
void LevelUp();

int counter = 0;

Character character;
Zombie zombie;

int main() {

    // Creating the character
    character.characterCreation();

    //Loading the HUD and the Moving function
    HUD();
    Moving();

    system("pause");

    return 0;
}

void HUD() {

    // This is a simple HUD for the game
    Sleep(500);
    system("cls");
    std::cout << "Name: " << character.name << "      health:" << character.totalHealth << "\nRace: " << character.race
        << "\nSex: " << character.sex << "\nLevel: " << character.level << "\nxp: " << character.current_xp << "\nXp to Level: " << character.xp_to_level << std::endl;
    Moving();
}

void CombatHUD() {

    // This is the combat HUD, when the character is in combat with a zombie.
    Sleep(500);
    system("cls");
    std::string tempName = zombie.monsterName[rand() % zombie.currentMonsterNames];
    std::cout << "Name: " << character.name << "              |               Monster Name: " << zombie.currentMonster << "\nHealth: " << character.totalHealth << "               |               Monster Health: " <<
        zombie.MonsterHp << "\nLevel: " << character.level << "                  |           Monster Level: " << zombie.MonsterLevel << std::endl;
}

void Combat()
{
    CombatHUD();
    int playerAttack;
    int MonsterAttack = 6 * zombie.MonsterLevel / 2;


    if (character.totalHealth >= 1 && zombie.MonsterHp >= 1)
    {
        std::cout << "\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Block\n";
        std::cout << "3. RUN!\n";
        std::cout << "\n";
        std::cin >> playerAttack;

        if (playerAttack == 1)
        {
            //Attack
            std::cout << "You are Attacking the Zombie... you did " << character.raceAttack << " to the " << zombie.currentMonster << std::endl;
            zombie.MonsterHp = zombie.MonsterHp - character.raceAttack;
            Sleep(1000);
            CombatHUD();
            if (zombie.MonsterHp >= 1)
            {
                std::cout << "\n";
                std::cout << "Monster is attacking.. \n";
                character.totalHealth = character.totalHealth - MonsterAttack;
                std::cout << "You suffered " << MonsterAttack << " hp " << character.totalHealth << std::endl;
                
                if (character.totalHealth <= 0)
                {
                    character.totalHealth = 0;
                }
                else if (zombie.MonsterHp <= 0)
                {

                    zombie.MonsterHp = 0;
                    LevelUp();
                    std::cout << "\n";
                    std::cout << "You Defeated " << zombie.currentMonster << " you are rewarded with " << zombie.MonsterXp << " xp.\nWell done!\n";

                    if (character.level != character.maxLevel)
                    {
                        character.current_xp += zombie.MonsterXp;
                        LevelUp();
                    }

                    Sleep(1000);
                    HUD();

                }
                Sleep(1000);
                Combat();
            }
        }
        else if (playerAttack == 2)
        {
            //Block
            std::cout << "Blocking \n";
            int i = rand() % 100 + 1;
            if (i >= 50)
            {
                std::cout << "You Blocked the incoming attack from the Zombie. That was pretty tough. \n";
                character.heal = character.level * 10 / 2;
                std::cout << "You have been healed for " << character.heal << std::endl;
                character.totalHealth += character.heal;
                Sleep(1000);
                Combat();
            }
            else
            {
                std::cout << "You failed to block the savage attack \n";
                character.totalHealth -= MonsterAttack;
                std::cout << "The Zombie bit you from the back " << MonsterAttack << " current hp " << character.totalHealth << std::endl;
                Sleep(1000);
                Combat();
            }
        }
        else if (playerAttack == 3)
        {
            //Run!
            std::cout << "You try to run \n";
            int x = rand() % 100 + 1;
            if (x >= 50)
            {
                std::cout << "You ran away \n";
                HUD();
            }
            else
            {
                std::cout << "You fail to run away \n";
                std::cout << "Monster does a savage attack on you \n";
                character.totalHealth -= MonsterAttack + 10;
                std::cout << "You suffered " << MonsterAttack + 10 << "Your current health is " << character.totalHealth << std::endl;
                Sleep(1000);
                Combat();
            }

        }
        else
        {
            std::cout << "Invalid Number\n";
            Sleep(500);
            Combat();
        }
    }
    if (character.totalHealth <= 1)
    {
        system("cls");
        std::cout << "You died! \nYou were level: " << character.level << "You got killed by " << zombie.currentMonster << std::endl;
        Sleep(2000);
        exit(0);
    }
    if (zombie.MonsterHp <= 1)
    {
        LevelUp();
        std::cout << "\n";
        std::cout << "You Defeated " << zombie.currentMonster << " you are rewarded with " << zombie.MonsterXp << " xp.\nWell done!\n";
        Sleep(1000);
        HUD();
    }
}

void Moving()
{
    //Simple Moving function
    int choice;

    std::cout << "\n\n";
    std::cout << "1. Move Forward\n";
    std::cout << "2. Move Relax\n";
    std::cout << "3. Move Backwards\n";
    std::cout << "\n";

    std::cin >> choice;

    if (choice == 1)
    {
        int temp = rand() % 100 + 1;
        std::cout << "You begin moving Forward...\n";
        if (temp >= 50)
        {
            zombie.zombieCreation();
            std::string tempName = zombie.monsterName[rand() % zombie.currentMonsterNames];
            std::cout << "A " << tempName << "! Prepare To Fight!\n";
            zombie.currentMonster = tempName;
            Sleep(1000);
            Combat();
        }
        std::cout << "You Find Nothing Of Interest\n";
        Sleep(1000);
        HUD();


    }
    else if (choice == 2)
    {
        std::cout << "You want to set up camp for the evening\n";
        if (character.totalHealth <= 99)
        {
            character.totalHealth += 10 * character.level;
        }
        std::cout << "You heal by resting, Health in now " << character.totalHealth << std::endl;
        Sleep(1000);
        HUD();

    }
    else if (choice == 3)
    {
        int temp = rand() % 100 + 1;
        std::cout << "You begin moving Backwards...\n";
        if (temp >= 50)
        {
            zombie.zombieCreation();
            std::string tempName = zombie.monsterName[rand() % zombie.currentMonsterNames];
            std::cout << "A " << tempName << "! Prepare To Fight!\n";
            zombie.currentMonster = tempName;
            Sleep(1000);
            Combat();
        }
        std::cout << "You Find Nothing Of Interest\n";
        Sleep(1000);
        HUD();


    }
    else {
        std::cout << "Invalid Number\n";
        Sleep(500);
        Moving();
    }




}

void LevelUp()
{
    character.current_xp = character.current_xp + zombie.MonsterXp;

    if (character.current_xp >= character.xp_to_level)
    {
        character.level++;
        character.xp_to_level = character.xp_to_level * 3 / 2;
        character.totalHealth = character.totalHealth + 20;
        character.maxHealth = character.totalHealth;
        std::cout << "You have just leveled up!!! Nice, the zombie wont stand a chance now, or will they? " << character.level << std::endl;
        std::cout << "Your total health increased by 20 points! Total max health is now " << character.totalHealth << std::endl;
        Sleep(1000);
        HUD();
    }
}

//void CreateMonster()
//{
//
//    MonsterHp = 30;
//
//    MonsterLevel = (rand() % 3) + character.level;
//    MonsterHp = (rand() % 30) * MonsterLevel;
//    MonsterXp = MonsterHp;
//
//    if (MonsterHp == 0)
//        CreateMonster();
//    if (MonsterLevel == 0)
//        CreateMonster();
//
//
//}

