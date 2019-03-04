#pragma once


#include <queue>
#include <thread>


class Map;
class Controller;
class SpawnerClass;
enum State;
class GameMode
{
public:
	static GameMode * GetInstance();

public:
	void Play();
	~GameMode();
	bool CheckMoveable();
	bool ChangeState(bool where_to_change,const State & new_state);
private:
	GameMode();
	static GameMode * mInstance;
	Map * mMap;
	Controller*  mController;
	SpawnerClass * mSpawner;
	std::queue<int> mInputBuffer;
	bool mSpawnTrig;
	bool mMoveTrig;
};