#ifndef __MISC_H__
#define __MISC_H__

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Audio.hpp>
#include "Wizard.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Dagger.h"
#include "Sword.h"
#include "Enemy.h"
#include "Rod.h"
#include "Goblin.h"
#include "Troll.h"
#include "Orc.h"

bool IntroText();
Player *SetupPlayer();
void ClearTerminal();

void readAndPrintTextAnimation(std::string &attackerAnimationNameFile, std::string &EnemyFrame);
void playerAttackAnimation(Player *&player, Enemy *&enemy);
void EnemyAttackAnimation(Enemy *&enemy, Player *&player);
Enemy *CreateEnemy();

#endif // __MISC_H__