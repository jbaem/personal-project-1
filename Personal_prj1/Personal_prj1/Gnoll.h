#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Gnoll : public Monster
{
public:
	Gnoll()
		:Monster(std::string("Gnoll"),
			MonsterStatus[MonsterType::Gnoll])
	{
		DropGold = 300;
	}
	virtual ~Gnoll() {}

private:

};