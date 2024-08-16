#pragma once

class Timer
{
public:
	// constructor destructor
	Timer();
	~Timer();
	
	// delete Function
	Timer(const Timer& _Other) = delete;
	Timer(Timer&& _Other) noexcept = delete;
	Timer& operator=(const Timer& _Other) = delete;
	Timer& operator=(Timer&& _Other) noexcept = delete;

public:
	static void TimeCheck(std::function<void()> _CheckFunc);

};

