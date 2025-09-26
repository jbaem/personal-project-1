#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Gnoll : public Monster
{
public:
	Gnoll()
		:Monster(std::string("Gnoll"),
			MonsterStatus[MonsterType::Gnoll],
			300)
	{
	}
	virtual ~Gnoll() {}
	bool UseSkill(Actor* Attacker, Actor* Target);


private:

};