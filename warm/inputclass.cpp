#include "inputclass.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
void InputClass::operator()(std::queue<int> & input_buffer)
{
	while (true)
	{
		mCh=_getch();
		if (mCh == 224)
		{
			mCh = _getch();
			if (mCh == kUP || mCh == kDOWN || mCh == kLEFT || mCh == kRIGHT)
			{
				
				input_buffer.emplace(mCh);
			}
			
		}
		Sleep(10);
	}
}
