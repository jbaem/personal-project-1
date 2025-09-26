#pragma once

#include <map>

#include "Status.h"
#include <string>

enum class JobType
{
	None,
	Novice,
	Warrior,
	Knight,
	Berserker
};

static std::map<JobType, std::string> JobName = {
	{JobType::None, "None"},
	{JobType::Novice, "Novice"},
	{JobType::Warrior, "Warrior"},
	{JobType::Knight, "Knight"},
	{JobType::Berserker, "Berserker"}
};

static std::map<JobType, Status> JobStatus = {
	{JobType::None, Status(
		50, 0, 0,
		10, 10, 20,
		5, 10, 10, 20
	)},
	{JobType::Novice, Status(
		10, 0, 50,
		3, 1, 1,
		0, 0, 0, 0
	)},
	{JobType::Warrior, Status(
		15, 0, 50,
		5, 3, 1,
		5, 0, 0, 0
	)},
	{JobType::Knight, Status(
		30, 0, 50,
		5, 5, 1,
		5, 0, 0, 0
	)},
	{JobType::Berserker, Status(
		10, 0, 50,
		7, 1, 3,
		15, 0, 10, 10
	)}
};