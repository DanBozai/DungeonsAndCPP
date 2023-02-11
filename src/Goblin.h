#ifndef GOBLIN_H
#define GOBLIN_H

#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
public:
    Goblin();
    ~Goblin();
    void printEnemyName() override;

private:
    const unsigned int Attack = 5;
};

#endif