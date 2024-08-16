#include "PreCompile.h"
#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::TimeCheck(std::function<void()> _CheckFunc)
{
	std::chrono::system_clock::time_point Start = std::chrono::system_clock::now();

	_CheckFunc();

	std::chrono::duration<double> Sec = std::chrono::system_clock::now() - Start;
	std::cout << "\n\n����ð�(��) : " << Sec.count() << " seconds\n\n";
}