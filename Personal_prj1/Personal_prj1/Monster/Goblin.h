#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Goblin : public Monster
{
public:
	Goblin()
		:Monster(std::string("Goblin"),
			MonsterStatus[MonsterType::Goblin],
			200)
	{
	}
	virtual ~Goblin() {}
	bool UseSkill(Actor* Attacker, Actor* Target);

private:

};