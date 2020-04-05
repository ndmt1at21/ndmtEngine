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
	class NDMTENGINE_API Shape :public Drawable, public Transformable
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
		Vector2i getOutlineAttribute() const;

		void setFillAttribute(const Vector2i& attribute);
		Vector2i getFillAttribute() const;

		virtual const RectInt getLocalBound() const = 0;
		virtual const RectInt getGlobalBound() const = 0;
	};
}


