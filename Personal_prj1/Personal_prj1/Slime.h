#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Slime : public Monster
{
public:
	Slime()
		:Monster(std::string("Slime"),
			MonsterStatus[MonsterType::Slime])
	{
		DropGold = 100;
	}

private:

};