#include "Warrior.h"


Warrior::Warrior(std::string name) : Player(name,WarriorType)
{
    std::cout << "Welcome to DungeonsAndCPP\n";
    std::cout << name << ", as a warrior, your training and physical prowess will be your greatest weapons as you explore the world and face its challenges.\n";
    std::cout << "Though battles may seem overwhelming and the road ahead perilous, your bravery and determination will see you through.\n";
    std::cout << "Step forward and embrace your destiny as a warrior, for a journey filled with excitement and glory.\n\n";
    system("pause");
    system("CLS");
    
}



Warrior::~Warrior()
{
    std::cout << "Warrior Dest\n";
}

void Warrior::Attack()
{
    std::cout << "Warrior Atack with" << std::endl;
}