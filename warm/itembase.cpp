#include "itembase.h"
#include <utility>
ItemBase::ItemBase(ItemBase && rhs)
{
	mPosition = std::move(rhs.mPosition);
	mState = std::move(rhs.mState);
}

ItemBase & ItemBase::operator=(ItemBase && rhs)
{

		if (this == &rhs)
		{
			return *this;
		}
		mPosition = std::move(rhs.mPosition);
		mState = std::move(rhs.mState);
		return *this;

	
	// TODO: 여기에 반환 구문을 삽입합니다.
}
