#include "Golem.h"


bool Golem::UseSkill(Actor* Attacker, Actor* Target)
{
	printf("[%s] Guardian 을 사용했습니다.\n", Name.c_str());

	SetHp(GetCurrentHp() + 100);
	Stat.Def += 100;
	Attack(Target);
	Stat.Def -= 100;

	return true;
}