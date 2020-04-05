#pragma once
#include "Graphics/Export.h"
#include "Graphics/Shape.h"
#include "Graphics/Rect.h"

namespace mt
{
	class ndmtEngine;

	class Circle :public Shape
	{
	private:
		int m_radius;

	public:
		Circle();
		Circle(int radius);
		~Circle();

		void setRadius(int radius);
		int getRadius();

		const RectInt getLocalBound();
		const RectInt getGlobalBound();

	protected:
		void draw(ndmtEngine* target);
		void drawOutline(ndmtEngine* target);
		void fill(ndmtEngine* target);
	};
}




