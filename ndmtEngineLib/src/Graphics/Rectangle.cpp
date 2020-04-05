#include "pch.h"
#include "Graphics/Rectangle.h"
#include "ndmtEngine.h"

namespace mt
{
	Rectangle::Rectangle()
	{

	}

	Rectangle::Rectangle(const Vector2i& size)
	{
		setSize(size);
	}

	Rectangle::Rectangle(const Rectangle& rect)
	{
		setSize(rect.m_size);
	}

	Rectangle::~Rectangle()
	{

	}

	void Rectangle::setSize(const Vector2i& size)
	{
		m_size = size;
		m_bound.left = m_bound.top = 0;
		m_bound.width = size.x;
		m_bound.height = size.y;
	}

	Vector2i Rectangle::getSize()
	{
		return m_size;
	}

	const RectInt Rectangle::getLocalBound()
	{
		return m_bound;
	}

	const RectInt Rectangle::getGlobalBound()
	{
		RectInt rect;
		rect = m_bound + m_position;

		return rect;
	}

	void Rectangle::draw(ndmtEngine* target)
	{
		if (m_bFill)
			fill(target);
		else
			drawOutline(target);
	}

	void Rectangle::drawOutline(ndmtEngine* target)
	{
		Line l1(Vector2i(m_position.x, m_position.y), Vector2i(m_position.x + m_size.x, m_position.y));
		Line l2(Vector2i(m_position.x, m_position.y), Vector2i(m_position.x, m_position.y + m_size.y));
		Line l3(Vector2i(m_position.x, m_position.y + m_size.y), Vector2i(m_position.x + m_size.x, m_position.y + m_size.y));
		Line l4(Vector2i(m_position.x + m_size.x, m_position.y), Vector2i(m_position.x + m_size.x, m_position.y + m_size.y));

		l1.setOutlineAttribute(m_outlineAttribute);
		l2.setOutlineAttribute(m_outlineAttribute);
		l3.setOutlineAttribute(m_outlineAttribute);
		l4.setOutlineAttribute(m_outlineAttribute);

		target->draw(&l1);
		target->draw(&l2);
		target->draw(&l3);
		target->draw(&l4);
	}

	void Rectangle::fill(ndmtEngine* target)
	{
		for (int y = m_position.y; y < m_position.y + m_size.y; y++)
		{
			for (int x = m_position.x; x < m_position.x + m_size.x; x++)
			{
				target->DrawPoint(x, y, m_fillAttribute.x, m_fillAttribute.y);
			}
		}
	}
}