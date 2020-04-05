#include "pch.h"
#include "Graphics/Line.h"
#include "ndmtEngine.h"

namespace mt
{
	Line::Line()
	{

	}

	Line::Line(const Vector2i& Start, const Vector2i& End)
	{
		setLine(Start, End);
	}

	Line::~Line()
	{

	}

	void Line::setLine(const Vector2i& Start, const Vector2i& End)
	{
		start = Start;
		end = End;

		m_bound.left = m_bound.top = 0;
		m_bound.width = std::abs(start.x - end.x);
		m_bound.height = std::abs(start.y - end.y);
	}

	Vector2i Line::getStart()
	{
		return start;

	}

	Vector2i Line::getEnd()
	{
		return end;
	}

	const RectInt Line::getLocalBound()
	{
		return m_bound;
	}

	const RectInt Line::getGlobalBound()
	{
		RectInt rect;
		rect = m_bound + m_position;

		return rect;
	}

	void Line::draw(ndmtEngine* target)
	{
		int dx = end.x - start.x;
		int dy = end.y - start.y;


		int dx1 = abs(dx); //test 0 < m < 1 or m > 1
		int dy1 = abs(dy);

		int px = 2 * dy1 - dx1;
		int py = 2 * dx1 - dy1;

		int x, y, xe, ye;

		//0 < m < 1
		if (dy1 <= dx1)
		{
			if (dx >= 0)
			{
				x = start.x; y = start.y; xe = end.x;
			}
			//user input high point before low point
			else
			{
				x = end.x; y = end.y; xe = start.x;
			}

			target->DrawPoint(x, y, m_outlineAttribute.x, m_outlineAttribute.y);

			for (int i = 0; x < xe; i++)
			{
				x = x + 1;
				if (px < 0)
					px = px + 2 * dy1;
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y++; else y--;
					px = px + 2 * (dy1 - dx1);
				}
				target->DrawPoint(x, y, m_outlineAttribute.x, m_outlineAttribute.y);
			}
		}
		else
		{
			if (dy >= 0)
			{
				x = start.x; y = start.y; ye = end.y;
			}
			else
			{
				x = end.x; y = end.y; ye = start.y;
			}

			target->DrawPoint(x, y, m_outlineAttribute.x, m_outlineAttribute.y);

			for (int i = 0; y < ye; i++)
			{
				y = y + 1;
				if (py <= 0)
					py = py + 2 * dx1;
				else
				{
					if ((dy < 0 && dx < 0) || (dy > 0 && dx > 0)) x++; else x--;
					py = py + 2 * (dx1 - dy1);
				}
				target->DrawPoint(x, y, m_outlineAttribute.x, m_outlineAttribute.y);
			}
		}
	}
}