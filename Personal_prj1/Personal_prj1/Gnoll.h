#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Gnoll : public Monster
{
public:
	virtual bool UseSkill(Actor* Target) override;

public:
	Gnoll()
		:Monster(std::string("Gnoll"),
			MonsterStatus[MonsterType::Gnoll],
			300) {}
	virtual ~Gnoll() {}
};