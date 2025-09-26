#include "Orc.h"

bool Orc::UseSkill(Actor* Attacker, Actor* Target)
{
	printf("[%s] Strong Attack 을 사용했습니다.\n", Name.c_str());

	Stat.Atk *= 2;
	Attack(Target);
	Stat.Atk /= 2;

	return true;
}