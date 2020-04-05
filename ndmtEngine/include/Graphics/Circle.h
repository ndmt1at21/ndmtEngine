#pragma once
#include "Graphics/Export.h"
#include "Graphics/Shape.h"
#include "Graphics/Rect.h"

namespace mt
{
	class ndmtEngine;

	class NDMTENGINE_API Circle :public Shape
	{
	private:
		int m_radius;

	public:
		Circle();
		Circle(int radius);
		~Circle();

		void setRadius(int radius);
		int getRadius() const;

		const RectInt getLocalBound() const;
		const RectInt getGlobalBound() const;

	protected:
		void draw(ndmtEngine* target) const;
		void drawOutline(ndmtEngine* target) const;
		void fill(ndmtEngine* target) const;
	};
}




