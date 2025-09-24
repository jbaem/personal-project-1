#pragma once

#include <map>

#include "Status.h"

enum class MonsterType
{
	Slime,
	Goblin,
	Gnoll,
	Orc,
	Golem
};

static std::map<MonsterType, Status> MonsterStatus = {
	{MonsterType::Slime, Status(
		20, 0, 10,
		5, 6, 20,
		0, 0, 0, 0
	)},
	{MonsterType::Goblin, Status(
		100, 0, 40,
		10, 12, 28,
		0, 10, 10, 20
	)},
	{MonsterType::Gnoll, Status(
		180, 0, 90,
		15, 20, 32,
		10, 10, 20, 20
	)}, 
	{MonsterType::Orc, Status(
		300, 0, 160,
		20, 30, 28,
		15, 10, 20, 20
	)},
	{MonsterType::Golem, Status(
		500, 0, 300,
		25, 40, 32,
		20, 10, 20, 20
	)}
};