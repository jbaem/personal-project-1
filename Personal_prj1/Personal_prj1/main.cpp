#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <crtdbg.h>
#include "GameManager.h"

using namespace std;

//#define TEST_MODE
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameManager GM;
#ifdef TEST_MODE

#else
	GM.PlayGame();
#endif

	return 0;
}
