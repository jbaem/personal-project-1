#pragma once

#include <string>
#include "NPC.h"
#include "Player.h"

class Innkeeper : public NPC
{
public:
	virtual void Talk(Player* InPlayer) override;

private:
	void Heal(Player* InPlayer, const int InNeedGold);

	std::string Name = "Innkeeper";

public:
	Innkeeper() = default;
	virtual ~Innkeeper() {}

};

