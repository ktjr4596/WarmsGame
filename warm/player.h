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
	std::vector<Point> mPosition;		// �÷��̾��� ��� �� ��ġ�� �����ϴ� ����
	IndexList mIndexLIst;				// mPosition�� ��� ����(�÷��̾� ������� ����)�� �����ϴ� ����Ʈ
	Direction mDirection;					// �÷��̾��� ���� ����
	Point mDeletePos;					// ���� ��� �� �����Ǿ�� ��( �÷��̾� ��� ����Ʈ���� ���� ������) ��ġ
	bool mTrig;						// ó�� ��� ���� Ʈ���� 
	bool mMakeBlockTrig;				// ����� ���� �߰� ���� ���� Ʈ����

	void AddBlockRear();				// ������ ��ġ�� ��� �߰�
};