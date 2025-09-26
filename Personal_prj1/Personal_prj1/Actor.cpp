#include <string>
#include <cstdio>

#include "Status.h"
#include "Actor.h"
#include "Utilities.h"
#include "Constants.h"

void Actor::Attack(Actor* Target)
{
	int Damage = CalculateDamage(ATTACK_MODIFIER);
	printf("[%s] %d 데미지로 일반 공격 시도!\n", Name.c_str(), Damage);
	Target->Defense(Damage, this);
	if (Stat.CurrentMp < Stat.Mp)
	{
		Stat.CurrentMp++;
	}
}

int Actor::CalculateDamage(float Modifier)
{
	int RandomNumber = GenerateRandomNumber(PERCENT_MIN, PERCENT_MAX);
	return static_cast<int>( RandomNumber < Stat.Crit
		? Stat.Atk * Modifier * (ATK_STANDARD + Stat.CritDmg) / ATK_STANDARD
		: Stat.Atk * Modifier
	);
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
		Damaged(Damage, Attacker);
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
	if (Stat.CurrentMp < Stat.Mp)
	{
		Stat.CurrentMp++;
	}
}

void Actor::Counter(Actor* Target)
{
	printf("\t=> [%s] 카운터 공격 발동\n", Name.c_str());
	Attack(Target);
}
