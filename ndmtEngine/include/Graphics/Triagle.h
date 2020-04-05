#pragma once

#ifdef NDMTENGINE_EXPORTS
#define NDMTENGINE_API __declspec(dllexport)
#else
#define NDMTENGINE_API __declspec(dllimport)
#endif

#include "Graphics/Drawable.h"

namespace mt
{
	class NDMTENGINE_API Triagle :public Drawable
	{
	};
}

