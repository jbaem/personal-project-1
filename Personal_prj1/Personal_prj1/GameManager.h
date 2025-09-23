#pragma once
#include "Player.h"
#include "Monster.h"
#include "UIManager.h"

class GameManager
{
public:
	void PlayGame();
	void InitPlayer();



private:
	UIManager* UI;
	
	Actor* User;
	Actor* Enemy;
};

