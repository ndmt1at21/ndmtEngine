#include "pch.h"
#include "Graphics/Shape.h"

namespace mt
{
	Shape::Shape()
	{
		m_outlineAttribute = { PIXEL_SOLID, FG_WHITE };
		m_fillAttribute = { PIXEL_SOLID, FG_WHITE };
		m_bFill = false;
	}

	Shape::~Shape()
	{

	}

	void Shape::setOutlineAttribute(const Vector2i& attribute)
	{
		m_outlineAttribute.x = attribute.x;
		m_outlineAttribute.y = attribute.y;
		m_bFill = false;
	}

	Vector2i Shape::getOutlineAttribute() const
	{
		return m_outlineAttribute;
	}

	void Shape::setFillAttribute(const Vector2i& attribute)
	{
		m_bFill = true;
		m_fillAttribute.x = attribute.x;
		m_fillAttribute.y = attribute.y;
	}

	Vector2i Shape::getFillAttribute() const
	{
		return m_fillAttribute;
	}
}
