#pragma once


class Timer
{
private:
	LARGE_INTEGER freq, start, end;
	double deltaTime_c, preTime, nowTime;
public:
	void Initalize();
	double deltaTime();
};

