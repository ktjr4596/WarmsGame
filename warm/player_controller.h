#pragma once
#include "player.h"
#include <queue>
#include <thread>
class Player;
class Controller
{
public:
	explicit Controller(std::queue<int> & input_buffer);
	void ProcessKey(int ch);
	void MovePlayer();
	void MakeNewBlock();
	Point GetNextPosition();
	Point GetDeletePosition();
	Point GetFrontPositon();
private:
	
	Player mPlayer;
	bool mTimerTrig=false;
	std::thread mControlThread;
};