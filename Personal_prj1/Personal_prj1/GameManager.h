#pragma once


#include "Player.h"
#include "Monster.h"
#include "UIManager.h"

#include "Instructor.h"
#include "Innkeeper.h"
#include "DungeonManager.h"

class GameManager
{
public:
	void PlayGame();
	void InitPlayer();

private:
	int StartChoice();
	int VillageChoice();
	
	Actor* User;
	Actor* Enemy;

	Instructor JobNPC;
	Innkeeper InnNPC;

	DungeonManager* Dungeon;
};

