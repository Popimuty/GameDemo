#pragma once
#include "SingleTone.h"

class Timer : public SingleTon<Timer>
{
	friend class SingleTon<Timer>;
private:
	Timer() = default;
	~Timer() = default;
private:
	LARGE_INTEGER freq, start, end;
	double deltaTime_c, preTime, nowTime;
public:
	void Initalize();
	void Update();
	double deltaTime();
};

