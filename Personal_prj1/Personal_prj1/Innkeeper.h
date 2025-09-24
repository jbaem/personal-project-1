#pragma once

#include "NPC.h"

class Innkeeper : public NPC
{
public:
	virtual void Talk() {}

	Innkeeper() = default;
	virtual ~Innkeeper() {}
};

