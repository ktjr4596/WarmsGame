#pragma once
#include "gtxy.h"
#include <iostream>
void ShowMainMenu()
{
	system("mode con: lines=30 cols=44");
	gtxy::gotoxy(20, 10);
	puts("Warms!");
	gtxy::gotoxy(17, 15);
	puts("Press Any Key");
	std::cin.get();

	system("cls");
}