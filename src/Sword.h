#ifndef SWORD_H
#define SWORD_H

#pragma once
#include "Item.h"
class Sword:public Item
{
public:
    Sword(std::string item_name);
    ~Sword();
   int getWeaponAttack() override;
    
private:

    int SwordAttack =100;
};

#endif