#pragma once

#include <string>
#include "NPC.h"
#include "Player.h"

class Innkeeper : public NPC
{
public:
	virtual void Talk(Player* InPlayer) override;
	void Heal(Player* InPlayer);

	Innkeeper() = default;
	virtual ~Innkeeper() {}

	std::string Name = "Innkeeper";
};

