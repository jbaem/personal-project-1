#pragma once

#include <string>

#include "Actor.h"
#include "Status.h"

class Monster : public Actor
{
public:
	virtual int MyTurn(Actor* Target) override;
	virtual bool UseSkill(Actor* Target) override;
	virtual void Die(Actor* Attacker) override;

	void PrintMonsterInfo();

protected:
	int SkillMana = 3;

public:
	Monster(std::string InName, Status& InStat, int InGold)
		: Actor(InName, InStat, InGold) {}
	virtual ~Monster() {}
};
