#pragma once
#include "map.h"
#include <vector>
#include <list>
extern const char * blocks[];

class IndexList
{
private:
	typedef int Item;
	class Node
	{
	public:
		Item mData;
		Node * mNext;
	public:
		Node(int item)
		{
			mData = item;
			mNext = nullptr;
		}
		Item GetData() const { return mData; }
	};

public:
	IndexList();
	~IndexList();
	bool PushList(const Item & item);
	void ChangeHead();
	Item GetFront() const { return mHead->GetData(); }
	Item GetRear() const { return mRear->GetData(); }
private:
	Node * mRear;
	Node * mHead;
	Node * mRear2nd;
	int mSize;
};

class Player 
{
public:

	Player();
	void ShowPosition();
	bool MovePosition();
	bool MakeBlock();
	Point GetFront() const { return mPosition[mIndexLIst.GetFront()]; }
	void ChangeDirection(Direction in_direction);
	Direction GetDirection() const {
		return mDirection;
	}
	Point GetDeletePosition() { return mDeletePos; }
private:
	std::vector<Point> mPosition;		// 플레이어의 블락 별 위치를 저장하는 벡터
	IndexList mIndexLIst;				// mPosition의 블락 순서(플레이어 진행방향 부터)를 저장하는 리스트
	Direction mDirection;					// 플레이어의 진행 방향
	Point mDeletePos;					// 다음 출력 때 삭제되어야 할( 플레이어 블락 리스트에서 제일 마지막) 위치
	bool mTrig;						// 처음 출력 구분 트리거 
	bool mMakeBlockTrig;				// 블락을 새로 추가 했을 때의 트리거

	void AddBlockRear();				// 마지막 위치에 블락 추가
};