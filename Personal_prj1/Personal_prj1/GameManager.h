#pragma once

#include "Instructor.h"
#include "Innkeeper.h"
#include "DungeonManager.h"
#include "Player.h"

class GameManager
{
public:
	void PlayGame();
	void InitPlayer();

	GameManager();
	~GameManager();

public:
	int StartChoice();
	int VillageChoice();
	
	Player* User = nullptr;

	Instructor JobNPC;
	Innkeeper InnNPC;

	DungeonManager* Dungeon = nullptr;
};

