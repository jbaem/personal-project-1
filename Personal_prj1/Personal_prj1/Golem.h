#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Golem : public Monster
{
public:
	Golem()
		:Monster(std::string("Golem"),
			MonsterStatus[MonsterType::Golem])
	{
		DropGold = 500;
	}
	virtual ~Golem() {}

private:

};