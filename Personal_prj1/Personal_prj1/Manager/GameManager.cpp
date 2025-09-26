#include "GameManager.h"

#include <string>
#include <cstdio>
#include <iostream>

#include "JobData.h"

#include "Player.h"
#include "Job.h"
#include "Novice.h"
#include "Status.h"
#include "ActorInfo.h"
#include "DungeonManager.h"

void GameManager::PlayGame()
{
	int InputNumber = 0;
	int ChoiceNumber = 0;
	
	const int EndGame = 2;
	while (StartChoice() != EndGame)
	{		
		while (true)
		{
			ChoiceNumber = VillageChoice();
			switch (ChoiceNumber)
			{
			case 1:
				Dungeon->DungeonChoice();
				break;
			case 2:
				JobNPC.Talk(static_cast<Player*>(User));
				break;
			case 3:
				InnNPC.Talk(static_cast<Player*>(User));
				break;
			default:
				break;
			}

			if (ChoiceNumber == 4)
			{
				break;
			}
		}
	}
}

int GameManager::StartChoice()
{
	int InputNumber = 0;
	while (true)
	{
		printf("--------------------------------------------------------------------\n");
		printf("\n\t\t\t<전직 RPG>\n\n");
		printf("게임을 시작하시겠습니까?\n");
		printf("1. 게임 시작\n");
		printf("2. 게임 종료\n");
		printf("\n>>> ");
		std::cin >> InputNumber;
		switch (InputNumber)
		{
		case 1:
		case 2:
			return InputNumber;
		default:
			continue;
		}
	}
}

int GameManager::VillageChoice()
{
	const int GoToDunGeon = 1;
	const int MeetInstruct = 2;
	const int MeetInnkeeper = 3;

	int InputNumber = 0;
	while (true)
	{
		User->PrintPlayerInfo();
		printf("--------------------------------------------------------------------\n");
		printf("\n\t\t\t<태초 마을>\n\n");
		printf("오늘은 무슨 일을 할까?\n");
		printf("1. 던전으로 향하기\n");
		printf("2. 교관에게 전직하러 가기\n");
		printf("3. 여관에 쉬러 가기\n");
		printf("4. 메인 화면으로\n");
		printf("\n>>> ");

		std::cin >> InputNumber;
		switch (InputNumber)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			return InputNumber;
		default:
			break;
		}
	}
}

void GameManager::InitPlayer()
{
	printf("\t\t\t<플레이어 설정중>\n");
	printf("당신의 영어 이름은?\n");
	printf(">>> ");
	std::string InputName;
	std::cin >> InputName;

	Job* FirstJob = new Novice(JobType::Novice);
	User = new Player(
		InputName,
		JobStatus[JobType::None],
		FirstJob
	);
	User->PrintPlayerInfo();
	printf("\n\t\t\t\t<설정 완료>\n\n\n");
}

GameManager::GameManager()
{
	InitPlayer();
	Dungeon = new DungeonManager(User);
}

GameManager::~GameManager()
{
	delete Dungeon;
	delete User;
}
