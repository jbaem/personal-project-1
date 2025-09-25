#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Orc : public Monster
{
public:
	Orc()
		:Monster(std::string("Orc"),
			MonsterStatus[MonsterType::Orc],
			400)
	{
	}
	virtual ~Orc() {}

private:

};