#pragma once
class ItemBase;
class SpawnerClass
{

public:
	
	static SpawnerClass * GetInstance();
	
	void SetSpawnTime(const int in_time) { mSpawnTime = in_time; };
	ItemBase * CreateItem();
private:
	static SpawnerClass * mInstace;
	int mSpawnTime;
	bool mSpawnTrig;
};