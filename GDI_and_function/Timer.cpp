#include "pch.h"
#include "Timer.h"




void Timer::Initalize() {
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);
	preTime = 0;
}

double Timer::deltaTime(){
	QueryPerformanceCounter(&end);
	nowTime = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;
	deltaTime_c = nowTime - preTime;
	preTime = nowTime;
	if (end.QuadPart >= 1000000000) {
		Timer::Initalize();
	}
	return deltaTime_c;
}