#include "pch.h"
#include "Graphics/Circle.h"
#include "Graphics/Line.h"
#include "ndmtEngine.h"

namespace mt
{
	Circle::Circle() :m_radius(0)
	{

	}

	Circle::Circle(int radius)
	{
		setRadius(radius);
	}

	Circle::~Circle()
	{

	}

	void Circle::setRadius(int radius)
	{
		m_radius = radius;
		m_bound.top = m_bound.left = 0;
		m_bound.width = m_bound.height = 2 * radius;
	}

	int Circle::getRadius() const
	{
		return m_radius;
	}

	const RectInt Circle::getLocalBound() const
	{
		return m_bound;
	}

	const RectInt Circle::getGlobalBound() const
	{
		RectInt rect;
		rect.left = m_bound.left + m_position.x;
		rect.top = m_bound.top + m_position.y;
		rect.width = m_bound.width;
		rect.width = m_bound.height;

		return rect;
	}

	void Circle::draw(ndmtEngine* target) const
	{
		if (m_bFill)
			drawOutline(target);
		else
			fill(target);
	}

	void Circle::drawOutline(ndmtEngine* target) const
	{
		// C
		int xc = m_radius + m_position.x;
		int yc = m_radius + m_position.y;

		//algorithm midpoint
		int x, y;
		x = 0;
		y = m_radius;

		int fi = 1 - m_radius;

		//8 point
		while (y >= x)
		{
			target->drawPoint(x + xc, y + yc, m_outlineAttribute.x, m_outlineAttribute.y);
			target->drawPoint(y + xc, x + yc, m_outlineAttribute.x, m_outlineAttribute.y);
			target->drawPoint(y + xc, -x + yc, m_outlineAttribute.x, m_outlineAttribute.y);
			target->drawPoint(x + xc, -y + yc, m_outlineAttribute.x, m_outlineAttribute.y);
			target->drawPoint(-x + xc, -y + yc, m_outlineAttribute.x, m_outlineAttribute.y);
			target->drawPoint(-y + xc, -x + yc, m_outlineAttribute.x, m_outlineAttribute.y);
			target->drawPoint(-y + xc, x + yc, m_outlineAttribute.x, m_outlineAttribute.y);
			target->drawPoint(-x + xc, y + yc, m_outlineAttribute.x, m_outlineAttribute.y);

			if (fi < 0)
			{
				fi = fi + 2 * x + 3;
			}
			else
			{
				fi = fi + 2 * (x - y--) + 5;
			}
			x++;
		}
	}

	void Circle::fill(ndmtEngine* target) const
	{
		// C
		int xc = m_radius + m_position.x;
		int yc = m_radius + m_position.y;

		//algorithm midpoint
		int x, y;
		x = 0;
		y = m_radius;

		int fi = 1 - m_radius;

		while (y >= x)
		{
			Line l1(Vector2i(-x + xc, y + yc), Vector2i(x + xc, y + yc));
			Line l2(Vector2i(-x + xc, y + yc), Vector2i(x + xc, y + yc));
			Line l3(Vector2i(-y + xc, x + yc), Vector2i(y + xc, x + yc));
			Line l4(Vector2i(-y + xc, -x + yc), Vector2i(y + xc, -x + yc));
			Line l5(Vector2i(-x + xc, -y + yc), Vector2i(x + xc, -y + yc));

			l1.setFillAttribute(Vector2i(m_fillAttribute.x, m_fillAttribute.y));
			l2.setFillAttribute(Vector2i(m_fillAttribute.x, m_fillAttribute.y));
			l3.setFillAttribute(Vector2i(m_fillAttribute.x, m_fillAttribute.y));
			l4.setFillAttribute(Vector2i(m_fillAttribute.x, m_fillAttribute.y));
			l5.setFillAttribute(Vector2i(m_fillAttribute.x, m_fillAttribute.y));

			if (fi < 0)
			{
				fi = fi + 2 * x + 3;
			}
			else
			{
				fi = fi + 2 * (x - y--) + 5;
			}
			x++;
		}
	}
}