#ifndef __SCENES_H__
#define __SCENES_H__

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Misc.h"
#include "Dagger.h"
#include "Sword.h"
#include "Rod.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Wizard.h"
#include "Player.h"
#include "Goblin.h"
#include "Troll.h"
#include "Orc.h"

void CleanTerminal();

void CrossRoadsScene(Player *&pt);

void ForestScene(Player *&playerPtr, sf::Music &musicP);
void VillageScene(Player *&playerPtr, sf::Music &musicP);
void CaveScene(Player *&playerPtr, sf::Music &musicP);
bool BattleScene(Player *&playerPtr, sf::Music &musicP);

bool chestScene();
Enemy *CreateEnemy();

#endif // __SCENES_H__