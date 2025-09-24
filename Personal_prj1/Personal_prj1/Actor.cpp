#include <string>

#include "Actor.h"
#include "Utilities.h"
#include "Status.h"

void Actor::Attack(Actor* Target)
{
	int Critical = GenerateRandomNumber(0, 99);
	int Damage = Stat.Atk;
	if (Critical < Stat.Crit)
	{
		Damage = Stat.Atk * (100 + Stat.CritDmg) / 100;
	}
	Target->Suffer(Damage, this);
}

void Actor::Suffer(int InDamage, Actor* Target)
{
	int Damage = InDamage * 200 / (200 + Stat.Def);

	int Reaction = GenerateRandomNumber(0, 99);
	if (Reaction >= Stat.Dodge)
	{
		// Damaged
		SetHp(Stat.CurrentHp - Damage);
	}
	else
	{
		// Dodge
	}

	Reaction = GenerateRandomNumber(0, 99);
	if (Reaction < Stat.Counter)
	{
		// Counter Attack
		Attack(Target);
	}
}

void Actor::SetHp(int InHp)
{
	Stat.Hp = Clamp(InHp, 0, Stat.Hp);
}

Actor::Actor(std::string InName, Status InStat)
	:Name(InName), Stat(InStat) {}
