#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)


#include <crtdbg.h>
#include <cstdio>
#include "GameManager.h"

#include <iostream>
#include "ActorInfo.h"
#include "Status.h"

using namespace std;

//#define TEST_MODE
//#define INPUT_MACRO
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


#ifdef INPUT_MACRO
	freopen("test.txt", "r", stdin);
#endif
	
	GameManager GM;
#ifdef TEST_MODE
	GM.InitPlayer();
	
	GM.PrintPlayerStatus();

	GM.User->LevelUp();

	GM.PrintPlayerStatus();
#else
	GM.PlayGame();
#endif

	return 0;
}
