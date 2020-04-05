#include "pch.h"
#include "System/Clock.h"

namespace mt
{
	Clock::Clock()
	{
		m_previousTime = sys_clock::now();
		m_currentTime = sys_clock::now();
	}

	Clock::~Clock() {}

	float Clock::getElapsedTime()
	{
		m_currentTime = sys_clock::now();
		std::chrono::duration<float> elapseTime = m_currentTime - m_previousTime;
		m_previousTime = m_currentTime;

		return elapseTime.count();
	}
}