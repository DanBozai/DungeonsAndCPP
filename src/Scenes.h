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

void CrossRoadsScene(Player *&pt, std::vector<Item *> &inventoryPtr);

void ForestScene(Player* &playerPtr, std::vector<Item *> &inventoryPtr);
void VillageScene(Player* &playerPtr, std::vector<Item *> &inventoryPtr);
void CaveScene(Player* &playerPtr, std::vector<Item *> &inventoryPtr);

bool chestScene();
//void BattleScene();

#endif // __SCENES_H__