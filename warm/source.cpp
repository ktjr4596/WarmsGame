#include <iostream>
#include <Windows.h>
#include "mainmenu.h"
#include "game-mode.h"
int main()
{


	
	gtxy::SetCursor(false);
	ShowMainMenu();
	GameMode * myGame = GameMode::GetInstance();
	if (myGame)
	{
		myGame->Play();
	}
	system("cls");
	puts("���ӿ��� \n");
	system("pause");

}


