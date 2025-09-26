#include <string>
#include <cstdio>

#include "Status.h"
#include "Actor.h"
#include "Utilities.h"

void Actor::Attack(Actor* Target)
{
	int Critical = GenerateRandomNumber(0, 99);
	int Damage = Stat.Atk;
	if (Critical < Stat.Crit)
	{
		Damage = Damage * (100 + Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 일반 공격 시도!\n", Name.c_str(), Damage);
	Target->Suffer(Damage, this);
}

void Actor::Suffer(int InDamage, Actor* Attacker)
{
	int Damage = InDamage * 200 / (200 + Stat.Def);

	int Reaction = GenerateRandomNumber(0, 99);
	if (Reaction >= Stat.Dodge)
	{
		// Damaged
		printf("\t=> [%s] %d 의 데미지를 입었습니다.\n", Name.c_str(), Damage);
		SetHp(Stat.CurrentHp - Damage);
		
		if (Stat.CurrentHp <= 0)
		{
			return;
		}
	}
	else
	{
		// Dodge
		printf("\t=> [%s] 회피했습니다.\n", Name.c_str());
		Stat.CurrentMp++;
	}

	Reaction = GenerateRandomNumber(0, 99);
	if (Reaction < Stat.Counter)
	{
		// Counter Attack
		printf("\t=> [%s] 카운터 공격 발동\n", Name.c_str());
		Attack(Attacker);
		Stat.CurrentMp++;
	}
}

int Actor::MyTurn(Actor* Target)
{
	Attack(Target);
	return 1;
}

void Actor::SetHp(int InHp)
{
	Stat.CurrentHp = Clamp(InHp, 0, Stat.Hp);
}

Actor::Actor(std::string InName, Status& InStat, int InGold)
	:Name(InName), Stat(InStat), Gold(InGold) {}
