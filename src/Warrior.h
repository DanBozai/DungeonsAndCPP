#ifndef WARRIOR_H
#define WARRIOR_H

#pragma once
#include "Player.h"
class Warrior : public Player
{
public:
    Warrior(std::string name);
    ~Warrior();

private:
    
    void Attack() override;
};

#endif