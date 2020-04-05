#pragma once

#include "Graphics/Export.h"
#include "Graphics/Shape.h"

namespace mt
{
	class NDMTENGINE_API Rectangle :public Shape
	{
	private:
		Vector2i m_size;

	public:
		Rectangle();
		Rectangle(const Vector2i& size);
		Rectangle(const Rectangle& rect);
		~Rectangle();

		void setSize(const Vector2i& size);
		Vector2i getSize() const;

		const RectInt getLocalBound() const;
		const RectInt getGlobalBound() const;

	protected:
		void draw(ndmtEngine* target) const;
		void drawOutline(ndmtEngine* target) const;
		void fill(ndmtEngine* target) const;
	};
}




