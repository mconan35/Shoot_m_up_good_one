#pragma once
#include <Windows.h>

class Timer
{
public:

	Timer();

	float m_total_time;
	float m_systeme_time;
	float m_elapsed_time;

	void UpdateTime();
	float GetTotalTime();
	float GetElapsedTime();

	virtual ~Timer() = default;
};

