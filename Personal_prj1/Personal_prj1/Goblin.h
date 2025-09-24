#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Goblin : public Monster
{
public:
	Goblin()
		:Monster(std::string("Goblin"),
			MonsterStatus[MonsterType::Goblin])
	{
		DropGold = 200;
	}
	virtual ~Goblin() {}

private:

};