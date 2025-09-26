#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Slime : public Monster
{
public:
	virtual bool UseSkill(Actor* Target) override;

public:
	Slime()
		:Monster(std::string("Slime"),
			MonsterStatus[MonsterType::Slime],
			100) {}
	virtual ~Slime() {}
};