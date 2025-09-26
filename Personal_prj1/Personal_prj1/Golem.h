#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Golem : public Monster
{
public:
	virtual bool UseSkill(Actor* Target) override;

public:
	Golem()
		:Monster(std::string("Golem"),
			MonsterStatus[MonsterType::Golem],
			500) {}
	virtual ~Golem() {}
};