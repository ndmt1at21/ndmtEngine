#include "pch.h"
#include "Text.h"
#include "ndmtEngine.h"

namespace mt
{
	std::wstring Text::m_fontType = L"default";
	std::map <int, Sprite*> Text::m_font;

	Text::Text()
	{
		m_col = 0x000F;
		m_align = 0;
	}

	Text::Text(const std::wstring& str)
	{
		m_str = str;
		m_col = 0x000F;
		m_align = 0;
	}

	Text::Text(const std::wstring& str, std::wstring m_fontType, int align)
	{
		m_str = str;
		m_col = 0x000F;
		setFontType(m_fontType);
		m_align = align;
	}

	Text::Text(const Text& text)
	{
		m_str = text.m_str;
		m_col = 0x000F;
		m_fontType = text.m_fontType;
		m_font = text.m_font;
		m_align = text.m_align;
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
		for (int i = 0; i < 256; i++)
		{
			Sprite* spr = m_font.find(i)->second;
			
			for (int x = 0; x < spr->getWidth(); x++)
			{
				for (int y = 0; y < spr->getHeight(); y++)
				{
					if (spr->getGlyph(x, y) != L' ')
					{
						spr->setColour(x, y, m_col);
					}
				}
			}
		}
	}

	void Text::setFontType(std::wstring fontType)
	{
		if (fontType == m_fontType)
			return;

		m_fontType = fontType;
		if (m_fontType == L"default")
			return;

		if (m_font.size() != 0)
		{
			for (int i = 0; i < 256; i++)
			{
				delete m_font.find(i)->second;
				m_font.erase(i);
			}
		}

		for (int i = 0; i < 256; i++)
		{
			wchar_t ch[2]{ (wchar_t)i };
			std::wstring s(ch);

			Sprite* spr = new Sprite(L"Font/" + m_fontType + L"/" + s + L".spr");
			m_font.insert(std::pair<int, Sprite*>(i, spr));
		}
	}

	void Text::setAlign(int align)
	{
		m_align = align;
	}

	void Text::draw(ndmtEngine* target) const
	{
		int spaceAlign = 0;

		if (m_align != 0)
		{
			for (int i = 0; i < (int)m_str.length(); i++)
				spaceAlign += m_font.find(m_str[i])->second->getWidth();

			if (m_align == 1)  //mid
				spaceAlign /= 2;
			else if (m_align == 2) //right
				spaceAlign += 0;
		}
		
		
		if (m_fontType == L"default")
		{
			for (int i = 0; i < (int)m_str.length(); i++)
				target->drawPoint(m_position.x - spaceAlign + i, m_position.y, m_str[i], m_col);
		}
		else
		{
			int prevWidth = 0;
			for (int i = 0; i < (int)m_str.length(); i++)
			{
				if (m_str[i] == L' ')
					prevWidth += 4;
				else
				{
					Sprite* spr = m_font.find(m_str[i])->second;
					spr->setPosition(mt::Vector2i(m_position.x - spaceAlign + prevWidth, m_position.y));

					prevWidth += spr->getWidth() + 1;

					target->draw(spr);
				}
			}
		}
	}
}