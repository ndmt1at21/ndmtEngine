#pragma once

#include "Graphics/Export.h"
#include "Graphics/Drawable.h"
#include "Graphics/Transformable.h"
#include "Graphics/Rect.h"
#include "Graphics/Color.h"
#include "Graphics/PixelType.h"
#include "System/Vector2.h"

namespace mt
{
	class Shape :public Drawable, public Transformable
	{
	protected:
		Vector2i m_outlineAttribute;
		Vector2i m_fillAttribute;
		bool m_bFill;
		RectInt m_bound;

	protected:
		Shape();
		virtual ~Shape();

	public:
		void setOutlineAttribute(const Vector2i& attribute);
		Vector2i getOutlineAttribute();

		void setFillAttribute(const Vector2i& attribute);
		Vector2i getFillAttribute();

		virtual const RectInt getLocalBound() = 0;
		virtual const RectInt getGlobalBound() = 0;
	};
}


