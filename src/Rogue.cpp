#include "Rogue.h"

Rogue::Rogue(std::string name) : Player(name,RogueType,RogueAttack,RogueHealth,"RogueAttack (")
{
    std::cout << "Welcome to DungeonsAndCPP\n";
    std::cout << name << ", as a rogue, your cunning and agility will be your greatest assets as you navigate the world and undertake daring endeavors.\n";
    std::cout << "Though the path ahead may be filled with danger and uncertainty, your quick wit and stealth will guide you to success.\n";
    std::cout << "Embrace your destiny as a rogue and embark on an adventure filled with thrills and riches.\n\n";
    system("pause");
    system("CLS");
}

Rogue::~Rogue()
{
}

