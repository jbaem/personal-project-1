#pragma once

#include <string>

#include "Actor.h"
#include "Status.h"
#include "ActorInfo.h"

class Monster : public Actor
{
public:
	ActorInfo Info();
	virtual int MyTurn(Actor* Target);

	void PrintMonsterInfo();
	virtual void Die(Actor* Attacker);
	virtual bool UseSkill(Actor* Attacker, Actor* Target);

	int SkillMana = 3;

	Monster(std::string InName, Status& InStat, int InGold)
		: Actor(InName, InStat, InGold) {}
	virtual ~Monster() {}
};
