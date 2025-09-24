#pragma once
#include "Monster.h"
#include "Player.h"
#include <utility>
#include "Actor.h"

using Turn = std::pair<float, Actor*>;

class DungeonManager
{
public:
	int DungeonChoice();

	DungeonManager() = default;
	~DungeonManager() = default;

private:
	int CurrentDungeon = 0;
	void GoToDungeon();
	int DungeonInput();
	bool CompareTurn(Turn o1, Turn o2);
	void Battle();
	Monster* MonsterGenerator();

private:
	Player* User = nullptr;
};
