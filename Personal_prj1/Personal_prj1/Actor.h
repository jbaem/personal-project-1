#pragma once

#include <string>

#include "Status.h"
class Actor
{

public:
	std::string Name = "Unknown";
	Status Stat;
	bool IsPlayer = false;

	virtual void Attack(Actor* Target);
	virtual void Suffer(int InDamage, Actor* Target);

	void SetHp(int InHp);
	int GetCurrentHp() const { return Stat.CurrentHp; }

	Actor(std::string InName, Status InStat);
	virtual ~Actor() {};
};