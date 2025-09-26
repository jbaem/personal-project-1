#include "Goblin.h"


bool Goblin::UseSkill(Actor* Target)
{
	printf("[%s] Fast Attack 을 사용했습니다.\n", Name.c_str());

	Attack(Target);
	Attack(Target);

	return true;
}