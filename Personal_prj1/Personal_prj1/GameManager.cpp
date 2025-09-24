#include "GameManager.h"
#include <string>
#include <cstdio>
#include <iostream>

#include "Novice.h"
#include "Status.h"
#include "Player.h"
#include "Job.h"

void GameManager::PlayGame()
{
	int InputNumber = 0;
	int ChoiceNumber = 0;

	// 플레이어 생성
	//InitPlayer();

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
				JobNPC.Talk();
				break;
			case 3:
				InnNPC.Talk();
				break;
			default:
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
		printf("1. 게임 시작\n");
		printf("2. 게임 종료\n");
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
		printf("1. 던전\n");
		printf("2. 전직\n");
		printf("3. 회복\n");
		std::cin >> InputNumber;
		switch (InputNumber)
		{
		case 1:
		case 2:
		case 3:
			return InputNumber;
		default:
			break;
		}
	}
}

void GameManager::InitPlayer()
{
	std::string InputName;
	printf("Input user name : ");
	std::cin >> InputName;

	Job* FirstJob = new Novice();
	User = new Player(
		InputName,
		Status(
			50, 0, 0,
			10, 10, 20,
			5, 10, 10, 20
		),
		FirstJob
	);
}
