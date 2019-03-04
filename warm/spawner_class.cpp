#include"spawner_class.h"

#include "itembase.h"
#include <chrono>
#include <ctime>

SpawnerClass * SpawnerClass::mInstace = nullptr;
SpawnerClass * SpawnerClass::GetInstance()
{
	if (mInstace == nullptr)
	{
		mInstace = new SpawnerClass;
		srand(time(0));
		return mInstace;
	}
	return nullptr;
}


ItemBase * SpawnerClass::CreateItem()
{
	int xPos = (rand() % (Map::Width - 2)) + 1;
	int yPos= (rand() % (Map::Height - 2)) + 1;

	return new ItemBase{ Point{xPos,yPos},State::BLOCK };
}
