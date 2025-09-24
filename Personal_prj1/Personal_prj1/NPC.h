#pragma once

class NPC
{
public:
	virtual void Talk() = 0;

	NPC() = default;
	virtual ~NPC() = default;
};