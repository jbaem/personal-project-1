#pragma once

#include "NPC.h"

class Instructor : public NPC
{
public:
	virtual void Talk() {}

	Instructor() = default;
	virtual ~Instructor() {}
};

