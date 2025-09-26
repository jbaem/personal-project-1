#pragma once

#include <string>

#include "Monster.h"
#include "MonsterData.h"

class Orc : public Monster
{
public:
	virtual bool UseSkill(Actor* Target) override;

public:
	Orc()
		:Monster(std::string("Orc"),
			MonsterStatus[MonsterType::Orc],
			400) {}
	virtual ~Orc() {}
};