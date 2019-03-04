#include "player.h"
#include "gtxy.h"


bool Player::MovePosition()
{
	switch (mDirection)
	{
	case Direction::LEFT:
		mDeletePos = mPosition[mIndexLIst.GetRear()];

		mPosition[mIndexLIst.GetRear()] = Point{ mPosition[mTrig ? mIndexLIst.GetFront() : 0].xPos -1, mPosition[mTrig ? mIndexLIst.GetFront() : 0].yPos };
		break;

	case Direction::RIGHT:
		mDeletePos = mPosition[mIndexLIst.GetRear()];

		mPosition[mIndexLIst.GetRear()] = Point{ mPosition[mTrig ? mIndexLIst.GetFront() : 0].xPos+1, mPosition[mTrig ? mIndexLIst.GetFront() : 0].yPos  };

		break;

	case Direction::UP:
		mDeletePos = mPosition[mIndexLIst.GetRear()];
		
		mPosition[mIndexLIst.GetRear()] = Point{ mPosition[mTrig?mIndexLIst.GetFront():0].xPos, mPosition[mTrig ? mIndexLIst.GetFront() : 0].yPos - 1 };
	

		break;

	case Direction::DOWN:
		mDeletePos = mPosition[mIndexLIst.GetRear()];

		mPosition[mIndexLIst.GetRear()] = Point{ mPosition[mTrig ? mIndexLIst.GetFront() : 0].xPos , mPosition[mTrig ? mIndexLIst.GetFront() : 0].yPos+1 };
		break;
	}
	mTrig = true;
	ShowPosition();
	return true;
}

bool Player::MakeBlock()
{
	AddBlockRear();
	return true;
}

void Player::ChangeDirection(Direction in_direction)
{

	mDirection = in_direction;
}

void Player::AddBlockRear()
{
	switch (mDirection)
	{
	case Direction::LEFT:
		mPosition.push_back(Point{ mPosition[mIndexLIst.GetRear()].xPos +1, mPosition[mIndexLIst.GetRear()].yPos });
		break;

	case Direction::RIGHT:
		mPosition.push_back(Point{ mPosition[mIndexLIst.GetRear()].xPos -1, mPosition[mIndexLIst.GetRear()].yPos });
		break;

	case Direction::UP:
		mPosition.push_back(Point{ mPosition[mIndexLIst.GetRear()].xPos, mPosition[mIndexLIst.GetRear()].yPos + 1 });
		break;

	case Direction::DOWN:
		mPosition.push_back(Point{ mPosition[mIndexLIst.GetRear()].xPos, mPosition[mIndexLIst.GetRear()].yPos - 1 });
		break;
	}
	mIndexLIst.PushList(mPosition.size() - 1);
	mMakeBlockTrig = true;
}


Player::Player()
	:mDirection(Direction::UP), mTrig(false), mDeletePos(Point{ 0,0 }),mIndexLIst()
{
	mPosition.push_back(Point{ Map::Width / 2,Map::Height / 2 });
	mIndexLIst.PushList(mPosition.size() - 1);
	//ShowPosition();
}

void Player::ShowPosition()
{


	mIndexLIst.ChangeHead();
		
	
	mMakeBlockTrig = false;
}

IndexList::IndexList()
{
	mHead = nullptr;
	mRear = nullptr;
	mRear2nd = nullptr;
	mSize = 0;
}

IndexList::~IndexList()
{
	Node * tempNode = mHead;
	while (mHead != nullptr)
	{
		mHead = mHead->mNext;
		delete tempNode;
		tempNode = mHead;
	}
}

bool IndexList::PushList(const Item & item)
{
	mSize++;
	if (mHead == nullptr)
	{
		Node *tempNode = new Node(item);
		mHead = tempNode;
		mRear = tempNode;
		return true;
	}
	
	Node * addNode = new Node(item);
	mRear->mNext = addNode;
	mRear = addNode;
	 if (mHead->mNext == mRear)
	{
		mRear2nd = mHead;
	}
	else
	{
		 mRear2nd = mRear2nd->mNext;
	}
	return true;
}

void IndexList::ChangeHead()
{

	if (mSize > 2)
	{
		Node * tempNode = mHead;
		Node * tempNode2 = mRear;

		mRear = mRear2nd;
		mHead = tempNode2;
		mRear->mNext = nullptr;
		mHead->mNext = tempNode;


		while (tempNode->mNext != mRear)
		{
			tempNode = tempNode->mNext;
		}
		mRear2nd = tempNode;
		return;
	}
	if (mSize > 1)
	{
		
		Node * tempNode = mHead;
		mRear->mNext = mHead;
		mHead->mNext = nullptr;
		
		
		mHead = mRear;
		mRear = tempNode;
		mRear2nd = mHead;
	}
}

