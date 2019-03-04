#pragma once
#include "map.h"

class ItemBase:private UnCopyable
{
public:
	ItemBase(const Point & position,const State & new_state)
		:mPosition(position),mState(new_state)
	{}
	ItemBase(ItemBase && rhs);

	ItemBase & operator=(ItemBase && rhs);

	Point GetPosition() const { return mPosition; }
	State GetState() const { return mState; }

private:
	Point mPosition;
	State mState;
};