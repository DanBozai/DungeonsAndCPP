#ifndef __MISC_H__
#define __MISC_H__

#pragma once

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "Wizard.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Dagger.h"
#include "Sword.h"
#include "Rod.h"
#include "Goblin.h"
#include "Troll.h"
#include "Orc.h"

bool IntroText();
Player *SetupPlayer();
void ClearTerminal();
int generateRandomNum();

#endif // __MISC_H__