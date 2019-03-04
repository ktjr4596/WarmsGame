#include "player_controller.h"
#include "player.h"
#include "inputclass.h"
#include "timerclass.h"

#include <thread>
#include <Windows.h>


Controller::Controller(std::queue<int> & input_buffer)
{
}



void Controller::ProcessKey(int ch)
{
	switch (ch)
	{
	case kLEFT:
		mPlayer.ChangeDirection(Direction::LEFT);
		break;

	case kRIGHT:
		mPlayer.ChangeDirection(Direction::RIGHT);
		break;

	case kUP:
		mPlayer.ChangeDirection(Direction::UP);
		break;

	case kDOWN:
		mPlayer.ChangeDirection(Direction::DOWN);
		break;
	}
}

void Controller::MovePlayer()
{
	mPlayer.MovePosition();
}

void Controller::MakeNewBlock()
{
	mPlayer.MakeBlock();
}

Point Controller::GetNextPosition()
{
	Point tempPoint = mPlayer.GetFront();
	switch (mPlayer.GetDirection())
	{
	case Direction::LEFT:
		tempPoint.xPos -= 1;
		break;

	case Direction::RIGHT:
		tempPoint.xPos += 1;
		break;

	case Direction::UP:
		tempPoint.yPos -= 1;
		break;
		
	case Direction::DOWN:
		tempPoint.yPos += 1;
		break;

	}
	
	return tempPoint;
}

Point Controller::GetDeletePosition()
{
	return mPlayer.GetDeletePosition();
}

Point Controller::GetFrontPositon()
{
	return mPlayer.GetFront();
}
