#ifndef SWORD_H
#define SWORD_H

#pragma once
#include "Weapon.h"
class Sword:public Weapon
{
public:
    Sword(std::string item_name);
    ~Sword();

private:

};

#endif