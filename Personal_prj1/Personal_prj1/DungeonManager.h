#pragma once
#include "Monster.h"
#include "Player.h"
#include <utility>
#include "Actor.h"

using Turn = std::pair<float, Actor*>;

class DungeonManager
{
public:
	void DungeonChoice();

	DungeonManager() = default;
	DungeonManager(Actor* InPlayer)
		:User(static_cast<Player*>(InPlayer)) { }
	~DungeonManager() = default;

	void GoToDungeon();
	int DungeonInput();
	void Battle();
	Monster* MonsterGenerator();

	int CurrentDungeon = 0;

private:
	Player* User = nullptr;
};

struct Comparator
{
	bool operator()(Turn p1, Turn p2)
	{
		return p1.first > p2.first;
	}
};
