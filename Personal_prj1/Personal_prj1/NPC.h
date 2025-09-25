#pragma once

#include "Player.h"

class NPC
{
public:
	virtual void Talk(Player* InPlayer) = 0;

	NPC() = default;
	virtual ~NPC() = default;
};