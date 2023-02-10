#include "Wizard.h"

Wizard::Wizard(std::string name) : Player(name,WizardType,"WizardAttack (")
{

    std::cout << "Welcome to DungeonsAndCPP\n";
    std::cout << name << ", as a wizard, your mastery of magic will aid you on your journey to explore the world's mysteries and claim its treasures.\n";
    std::cout << "Though challenges and darkness may try to hinder your quest, your skills give you the power to overcome and unlock the secrets of the world.\n";
    std::cout << "Embrace your destiny and embark on an adventure of a lifetime.\n\n";

    system("pause");
    system("CLS");
}

Wizard::~Wizard()
{
    std::cout << "Wizard Dest\n";
}

void Wizard::Attack()
{
    std::cout << "Wizard Atack with" << std::endl;
}