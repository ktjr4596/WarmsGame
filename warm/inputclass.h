#pragma once
#include "map.h"
#include <queue>
 const int kUP = 72;
 const int kLEFT = 75;
 const int kRIGHT = 77;
 const int kDOWN = 80;

class InputClass
{
public:
	void operator()(std::queue<int> & input_buffer);
private:
	int mCh;
};