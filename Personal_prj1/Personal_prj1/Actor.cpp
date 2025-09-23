#include "Actor.h"

void Actor::Attack(Actor* Target)
{
	Target->Suffer(Atk);
}

void Actor::Suffer(int InDamage)
{
	int Damage = static_cast<int>((100.0f / static_cast<float>(100 + InDamage)) * Def);
	
}
