#include "Instructor.h"

#include <iostream>
#include <cstdio>

#include "Player.h"
#include "Job.h"
#include "JobData.h"

#include "Novice.h"
#include "Warrior.h"
#include "Knight.h"
#include "Berserker.h"


void Instructor::Talk(Player* InPlayer)
{
	int InputNumber = 0;
	while (true)
	{
		printf("[%s] 더 강해지고 싶니?\n", Name.c_str());
		printf("1. 전직 하기\n");
		printf("2. 돌아가기\n");
		printf(">>> ");
		std::cin >> InputNumber;
		
		switch (InputNumber)
		{
		case 1:
			ClassUp(InPlayer);
			return;
		case 2:
			printf("[%s] 아직 전직하고 싶지 않습니다.\n", InPlayer->Name.c_str());
			return;
		default:
			break;
		}
	}
}

void Instructor::ClassUp(Player* InPlayer)
{
	Job* PlayerJob = InPlayer->GetJob();
	if (InPlayer->GetLevel() < PlayerJob->NeedLevelToNextDegree)
	{
		printf("[%s] 넌 아직 전직할 수 없어. %d 레벨까지 성장하고 다시 와\n", Name.c_str(), PlayerJob->NeedLevelToNextDegree);
		return;
	}

	int InputNumber = 0;
	while (true)
	{
		printf("[%s] 무엇으로 전직하고 싶니?\n", Name.c_str());
		
		int JobCount = 1;
		for (auto Type : PlayerJob->NextJobs)
		{
			printf("%d. %s\n", JobCount, JobName[Type].c_str());
			JobCount++;
		}
		printf("%d. 돌아가기\n", JobCount);
		
		if (InputNumber > JobCount || InputNumber <= 0)
		{
			continue;
		}
		if (InputNumber == JobCount)
		{
			printf("[%s] 아직 전직하고 싶지 않습니다.\n", InPlayer->Name.c_str());
			return;
		}
		
		delete InPlayer->CurrentJob;

		JobType NextJobType = PlayerJob->NextJobs[InputNumber];
		InPlayer->CurrentJob = MatchJob(NextJobType);
		if (!InPlayer->CurrentJob)
		{
			printf("전직 실패!!!\n");
		}
		printf("[%s] %s 으로 전직했습니다.\n", InPlayer->Name.c_str(), JobName[NextJobType].c_str());
		printf("[%s] 한층 강해진 기분이 듭니다.\n", InPlayer->Name.c_str());
	}
}

Job* Instructor::MatchJob(JobType InType)
{
	Job* Result = nullptr;
	switch (InType)
	{
	case JobType::None:
		break;
	case JobType::Novice:
		Result = new Novice(JobType::None);
		break;
	case JobType::Warrior:
		Result = new Warrior(JobType::Warrior);
		break;
	case JobType::Knight:
		//Result = new Knight(JobType::Knight);
		break;
	case JobType::Berserker:
		//Result = new Berserker(JobType::Berserker);
		break;
	default:
		break;
	}
	return Result;
}