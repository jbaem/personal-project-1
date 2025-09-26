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

private:
	void GoToDungeon();
	int DungeonInput();
	void Battle();
	Monster* MonsterGenerator();

	Player* User = nullptr;
	int CurrentDungeon = 0;

public:
	DungeonManager(Actor* InPlayer)
		:User(static_cast<Player*>(InPlayer)) {
	}
	~DungeonManager() = default;
};

struct Comparator
{
	bool operator()(Turn p1, Turn p2)
	{
		return p1.first > p2.first;
	}
};
