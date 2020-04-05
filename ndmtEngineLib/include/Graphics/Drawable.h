#pragma once

namespace mt
{
	class ndmtEngine;

	class  Drawable
	{
	public:
		virtual ~Drawable() {}
		virtual void draw(ndmtEngine* target) = 0;
	};
}



