#include "Timer.h"

Timer::Timer() {
	m_total_time = 0;
	m_systeme_time = 0;
	m_elapsed_time = 0;
}

void Timer::UpdateTime() {
	DWORD current_systeme_time = timeGetTime();
	DWORD elapsed_time = current_systeme_time - m_systeme_time;
	m_systeme_time = current_systeme_time;
	m_elapsed_time = elapsed_time/1000.0f;
	m_total_time += m_elapsed_time;
}

float Timer::GetTotalTime()
{
	return m_total_time;
}

float Timer::GetElapsedTime()
{
	return m_elapsed_time;
}
