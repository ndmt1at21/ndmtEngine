#pragma once

#include "Graphics/Export.h"
#include "Graphics/Shape.h"

namespace mt
{
	class ndmtEngine;

	class Line :public Shape
	{
	private:
		Vector2i start;
		Vector2i end;

	public:
		Line();
		Line(const Vector2i& start, const Vector2i& end);
		~Line();

		void setLine(const Vector2i& start, const Vector2i& end);
		Vector2i getStart();
		Vector2i getEnd();

		const RectInt getLocalBound();
		const RectInt getGlobalBound();

	protected:
		void draw(ndmtEngine* target);
	};
}