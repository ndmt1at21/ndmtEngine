#include "pch.h"
#include "Graphics/Triagle.h"
#include "ndmtEngine.h"

namespace mt
{
	Triagle::Triagle()
	{

	}

	Triagle::Triagle(const Vector2i& v1, const Vector2i& v2, const Vector2i& v3)
	{
		m_v1 = v1;
		m_v2 = v2;
		m_v3 = v3;
	}

	Triagle::~Triagle()
	{

	}

	void Triagle::setVertex(const Vector2i& v1, const Vector2i& v2, const Vector2i& v3)
	{
		m_v1 = v1;
		m_v2 = v2;
		m_v3 = v3;
	}

	Vector2i Triagle::getVertex1() const
	{
		return m_v1;
	}

	Vector2i Triagle::getVertex2() const
	{
		return m_v2;
	}
	Vector2i Triagle::getVertex3() const
	{
		return m_v3;
	}

	void Triagle::draw(ndmtEngine* target) const
	{
		Line l1(Vector2i(m_v1.x, m_v1.y), Vector2i(m_v2.x, m_v2.y));
		Line l2(Vector2i(m_v2.x, m_v2.y), Vector2i(m_v3.x, m_v3.y));
		Line l3(Vector2i(m_v3.x, m_v3.y), Vector2i(m_v1.x, m_v1.y));

		l1.setOutlineAttribute(m_outlineAttribute);
		l2.setOutlineAttribute(m_outlineAttribute);
		l3.setOutlineAttribute(m_outlineAttribute);

		target->draw(&l1);
		target->draw(&l2);
		target->draw(&l3);
	}

	void Triagle::fill(ndmtEngine* target) const
	{
		//m_v2.y between m_v1.y and m_v3.y
		//find y max
		if (m_v2.y >= m_v3.y && m_v2.y >= m_v1.y)
		{
			std::swap(m_v2.x, m_v3.x); std::swap(m_v2.y, m_v3.y);
		}
		else if (m_v1.y >= m_v2.y && m_v1.y >= m_v3.y)
		{
			std::swap(m_v1.x, m_v3.x); std::swap(m_v1.y, m_v3.y);
		}

		//find min
		if (m_v2.y <= m_v1.y)
		{
			std::swap(m_v2.x, m_v1.x); std::swap(m_v2.y, m_v1.y);
		}

		//scan line algorithm
		float fml, fmr, fmb;
		fml = (float)(m_v2.x - m_v1.x) / (m_v2.y - m_v1.y);
		fmr = (float)(m_v3.x - m_v1.x) / (m_v3.y - m_v1.y);
		fmb = (float)(m_v2.x - m_v3.x) / (m_v2.y - m_v3.y);

		float xl, xr;
		int y;

		//flat bot
		xl = xr = float(m_v1.x);
		y = m_v1.y;

		while (y <= m_v2.y)
		{
			Line l(Vector2i(xl, y), Vector2i(xr, y));
			l.setOutlineAttribute(m_fillAttribute);
			target->draw(&l);

			xl = xl + fml;
			xr = xr + fmr;
			y++;
		}

		//flat peak
		xl = xr = float(m_v3.x);
		y = m_v3.y;

		while (y > m_v2.y)
		{
			Line l(Vector2i(xl, y), Vector2i(xr, y));
			l.setOutlineAttribute(m_fillAttribute);
			target->draw(&l);

			xl = xl - fmr;
			xr = xr - fmb;
			y--;
		}
	}
}