#include "Monster.h"

#include <cstdlib>

#include "Status.h"
#include "Actor.h"

Monster::Monster(std::string InName, Status InStat)
	: Actor(InName, InStat)
{
	float RandomFactor = 0.9f + ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.2f);
}
