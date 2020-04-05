#pragma once

#include "Graphics/Export.h"
#include "Graphics/Shape.h"

namespace mt
{
	class ndmtEngine;

	class NDMTENGINE_API Line :public Shape
	{
	private:
		Vector2i start;
		Vector2i end;

	public:
		Line();
		Line(const Vector2i& start, const Vector2i& end);
		~Line();

		void setLine(const Vector2i& start, const Vector2i& end);
		Vector2i getStart() const;
		Vector2i getEnd() const;

		const RectInt getLocalBound() const;
		const RectInt getGlobalBound() const;

	protected:
		void draw(ndmtEngine* target) const;
	};
}