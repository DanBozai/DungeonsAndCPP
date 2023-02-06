#ifndef ROGUE_H
#define ROGUE_H

#pragma once
#include "Player.h"
class Rogue:public Player
{
public:
    Rogue(std::string name);
    ~Rogue();

private:
    void Attack() override;

};

#endif