#ifndef ORC_H
#define ORC_H

#pragma once
#include "Enemy.h"

class Orc : public Enemy
{
public:
    Orc();
    ~Orc();
    void printEnemyName() override;

private:
};

#endif