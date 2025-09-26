#include "Slime.h"

bool Slime::UseSkill(Actor* Attacker, Actor* Target)
{
	printf("[%s] Self Healing 을 사용했습니다.\n", Name.c_str());

	Attacker->SetHp(Attacker->GetCurrentHp() + 10);
	return true;
}