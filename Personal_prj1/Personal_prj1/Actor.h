#pragma once

#include <string>

#include "Status.h"
#include "Utilities.h"

class Actor
{
public:
	virtual int MyTurn(Actor* Target) = 0;

	virtual void Attack(Actor* Target);
	virtual bool UseSkill(Actor* Target) = 0;
	virtual int CalculateDamage(float Modifier);

	virtual void Defense(int InDamage, Actor* Attacker);
	virtual void Damaged(int InDamage, Actor* Attacker);
	virtual void Dodge();
	virtual void Counter(Actor* Target);
	virtual void Die(Actor* Attacker) = 0;

	bool CheckPlayer() const { return IsPlayer; }

	inline std::string GetName() const { return Name; }
	inline Status GetStatus() const { return Stat; }
	inline int GetCurrentHp() const { return Stat.CurrentHp; }
	inline void SetHp(int InHp) { Stat.CurrentHp = Clamp(InHp, 0, Stat.Hp); }
	inline int GetGold() const { return Gold; }

protected:
	std::string Name = "Unknown";
	Status Stat;
	bool IsPlayer = false;
	int Gold = 0;

public:
	Actor(std::string InName, Status& InStat, int InGold)
		:Name(InName), Stat(InStat), Gold(InGold) {};
	virtual ~Actor() {};
};