#ifndef WEAPON_H
#define WEAPON_H

#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
    Weapon(std::string item_name);
    virtual ~Weapon();

private:
    int AttackPower;
    int MagicPower;
    std::string ItemType;
};

#endif