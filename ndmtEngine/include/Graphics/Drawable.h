#pragma once

#include "Graphics/Export.h"

namespace mt
{
	class ndmtEngine;

	class NDMTENGINE_API  Drawable
	{
	public:
		virtual ~Drawable() {}
		virtual void draw(ndmtEngine* target) const = 0;
	};
}



