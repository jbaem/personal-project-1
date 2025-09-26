#pragma once

#include <string>

#include "Status.h"

class Actor
{
public:
	std::string Name = "Unknown";
	Status Stat;
	bool IsPlayer = false;
	int Gold = 0;

	virtual void Attack(Actor* Target);
	virtual void Suffer(int InDamage, Actor* Target);
	virtual void Die(Actor* Attacker) = 0;
	virtual int MyTurn(Actor* Target);

	void SetHp(int InHp);
	int GetCurrentHp() const { return Stat.CurrentHp; }

	Actor(std::string InName, Status& InStat, int InGold);
	virtual ~Actor() {};
};