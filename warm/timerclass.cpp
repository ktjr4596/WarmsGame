#include "timerclass.h"

void Timer::operator()(bool & timer_trig)
{
	while (true)
	{
		if (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - mStart).count() > mTrigTime)
		{
			mStart = std::chrono::high_resolution_clock::now();
			timer_trig = true;
		}
		else
		{
			timer_trig = false;
		}
	}
}
