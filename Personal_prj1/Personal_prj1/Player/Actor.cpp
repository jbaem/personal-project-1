#include <string>
#include <cstdio>

#include "Status.h"
#include "Actor.h"
#include "Utilities.h"
#include "Constants.h"

void Actor::Attack(Actor* Target)
{
	int Critical = GenerateRandomNumber(0, 99);
	int Damage = CalculateDamage();
	int Damage = Stat.Atk;
	if (Critical < Stat.Crit)
	{
		Damage = Damage * (ATK_STANDARD + Stat.CritDmg) / ATK_STANDARD;
	}
	printf("[%s] %d 데미지로 일반 공격 시도!\n", Name.c_str(), Damage);
	Target->Damaged(Damage, this);
}

int Actor::CalculateDamage()
{
	int RandomNumber = GenerateRandomNumber(0, 99);
	return RandomNumber < Stat.Crit
		? Stat.Atk * (ATK_STANDARD + Stat.CritDmg) / ATK_STANDARD
		: Stat.Atk;
}

void Actor::Defense(int InDamage, Actor* Attacker)
{
	int Damage = InDamage * DEF_STANDARD / (DEF_STANDARD + Stat.Def);


	int RandomNumber = GenerateRandomNumber(PERCENT_MIN, PERCENT_MAX);
	if (RandomNumber < Stat.Dodge)
	{
		Dodge();
	}
	else
	{
		Damaged(InDamage, Attacker);
	}

	RandomNumber = GenerateRandomNumber(PERCENT_MIN, PERCENT_MAX);
	if (RandomNumber < Stat.Counter)
	{
		Counter(Attacker);
	}
}

void Actor::Damaged(int InDamage, Actor* Attacker)
{
	printf("\t=> [%s] %d 의 데미지를 입었습니다.\n", Name.c_str(), InDamage);
	SetHp(Stat.CurrentHp - InDamage);

	if (Stat.CurrentHp <= DIE_HP)
	{
		return;
	}
}

void Actor::Dodge()
{
	printf("\t=> [%s] 회피했습니다.\n", Name.c_str());
	Stat.CurrentMp++;
}

void Actor::Counter(Actor* Target)
{
	printf("\t=> [%s] 카운터 공격 발동\n", Name.c_str());
	Attack(Target);
	Stat.CurrentMp++;
}
