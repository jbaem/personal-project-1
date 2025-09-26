#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Golem : public Monster
{
public:
	Golem()
		:Monster(std::string("Golem"),
			MonsterStatus[MonsterType::Golem],
			500)
	{
	}
	virtual ~Golem() {}
	bool UseSkill(Actor* Attacker, Actor* Target);

private:

};