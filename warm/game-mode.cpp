#include "game-mode.h"
#include "map.h"
#include "player_controller.h"
#include "inputclass.h"
#include "timerclass.h"
#include "spawner_class.h"
#include "itembase.h"
GameMode * GameMode::mInstance = nullptr;

GameMode * GameMode::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameMode();

		return mInstance;
	}
	return nullptr;
}

void GameMode::Play()
{
	std::thread mTimerThread(Timer(), std::ref(mMoveTrig));			//movetimer를 돌리는 쓰레드
	std::thread mInputThread(InputClass(), std::ref(mInputBuffer));	// 입력처리 클래스 돌리는 쓰레드
	Timer spawnTimer(5.0);
	std::thread spawnThread(spawnTimer, std::ref(mSpawnTrig));			// spawntimer를 돌리는 쓰레드
	ItemBase * newItem = nullptr;
	ChangeState(true, State::PLAYER);
	while (true)
	{
		
		if (mSpawnTrig)
		{
			newItem= mSpawner->CreateItem();
			mMap->SetPointState(newItem->GetPosition(), newItem->GetState());
			delete newItem;
			newItem = nullptr;
		}

		if (mMoveTrig)
		{
			if (CheckMoveable())
			{
				mController->MovePlayer();
				ChangeState(false, State::BLANK);
				ChangeState(true, State::PLAYER);
			}
			else
			{
				
				break;
			}
		}
		if (!mInputBuffer.empty())
		{
			mController->ProcessKey(mInputBuffer.front());
			mInputBuffer.pop();

		}
	}
	mInputThread.detach();
	mTimerThread.detach();
	spawnThread.detach();
}

GameMode::~GameMode()
{
	delete mMap;
	delete mController;
	delete mSpawner;
}

bool GameMode::CheckMoveable()
{
	
	switch (mMap->GetPointState(mController->GetNextPosition().xPos, mController->GetNextPosition().yPos))
	{
	case State::WALL:
		return false;

	case State::BLANK:
		return true;

	case State::PLAYER:
		return false;

	case State::BLOCK:
		mController->MakeNewBlock();
		return true;

	} 

}

bool GameMode::ChangeState(bool where_to_change, const State & new_state)
{
	if (where_to_change)
	{
		mMap->SetPointState(mController->GetFrontPositon(), new_state);
	}
	else
	{
		mMap->SetPointState(mController->GetDeletePosition(), new_state);
	}
	return false;
}


GameMode::GameMode()
{
	mMap= new Map;
	mController = new Controller(mInputBuffer);
	mMoveTrig = false;
	mSpawner = SpawnerClass::GetInstance();
	mSpawnTrig = false;

}




