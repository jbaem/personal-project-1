#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Slime : public Monster
{
public:
	Slime()
		:Monster(std::string("Slime"),
			MonsterStatus[MonsterType::Slime],
			100)
	{
	}

	virtual bool UseSkill(Actor*, Actor*);
};