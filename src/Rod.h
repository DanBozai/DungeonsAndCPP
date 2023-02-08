#ifndef ROD_H
#define ROD_H

#pragma once
#include "Item.h"
class Rod : public Item
{
public:
    Rod(std::string item_name);
    ~Rod();
    int getWeaponAttack() override;

private:
    int rodAttack=50;
};

#endif