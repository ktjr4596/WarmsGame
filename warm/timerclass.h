#pragma once
#include <chrono>
class Timer
{
public:
	explicit Timer(double new_time=0.5):mStart(std::chrono::high_resolution_clock::now()),mTrigTime(new_time)
	{}
	void SetTrigTime(const double new_time) { mTrigTime = new_time; };
	void operator()(bool & timer_trig);
private:
	std::chrono::high_resolution_clock::time_point mStart;
	double mTrigTime=0.5;
};