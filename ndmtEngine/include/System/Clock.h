#pragma once

#include "System/Export.h"
#include <chrono>

namespace mt
{
	typedef std::chrono::system_clock sys_clock;

	class NDMTENGINE_API Clock
	{
	private:
		sys_clock::time_point m_previousTime;
		sys_clock::time_point m_currentTime;

	public:
		Clock();
		~Clock();

		float getElapsedTime();
	};
}
