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

private:
	int StartChoice();
	int VillageChoice();
	
	Player* User = nullptr;
	DungeonManager* Dungeon = nullptr;

	Instructor JobNPC;
	Innkeeper InnNPC;

public:
	GameManager();
	~GameManager();

};

