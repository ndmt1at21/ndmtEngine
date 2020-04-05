#pragma once

#include "Graphics/Export.h"
#include "Graphics/Shape.h"

namespace mt
{
	class Rectangle :public Shape
	{
	private:
		Vector2i m_size;

	public:
		Rectangle();
		Rectangle(const Vector2i& size);
		Rectangle(const Rectangle& rect);
		~Rectangle();

		void setSize(const Vector2i& size);
		Vector2i getSize();

		const RectInt getLocalBound();
		const RectInt getGlobalBound();

	protected:
		void draw(ndmtEngine* target);
		void drawOutline(ndmtEngine* target);
		void fill(ndmtEngine* target);
	};
}




