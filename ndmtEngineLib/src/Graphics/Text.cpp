#include "pch.h"
#include "Text.h"
#include "ndmtEngine.h"

namespace mt
{
	Text::Text()
	{
		m_col = 0x000F;
	}

	Text::Text(const std::wstring& str)
	{
		m_str = str;
		m_col = 0x000F;
	}

	Text::Text(const Text& text)
	{
		m_str = text.m_str;
		m_col = 0x000F;
	}

	Text::~Text()
	{

	}

	void Text::setText(const std::wstring& str)
	{
		m_str = str;
	}

	void Text::setColor(short col)
	{
		m_col = col;
	}

	void Text::draw(ndmtEngine* target)
	{
		for (int i = 0; i < (int)m_str.length(); i++)
		{
			target->DrawPoint(m_position.x + i, m_position.y, m_str[i], m_col);
		}
	}
}