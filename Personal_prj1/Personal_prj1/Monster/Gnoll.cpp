#include "Gnoll.h"

bool Gnoll::UseSkill(Actor* Attacker, Actor* Target)
{
	printf("[%s] Surprise Attack 을 사용했습니다.\n", Name.c_str());

	Stat.Crit += 40;
	Attack(Target);
	Stat.Crit -= 40;

	return true;
}
