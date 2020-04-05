#include "pch.h"
#include "Graphics/Sprite.h"
#include "ndmtEngine.h"

namespace mt
{
	void Sprite::Create(int w, int h)
	{
		m_width = w;
		m_height = h;
		m_Glyphs = new short[w * h];
		m_Colours = new short[w * h];

		for (int i = 0; i < w * h; i++)
		{
			m_Glyphs[i] = L' ';
			m_Colours[i] = FG_BLACK;
		}

		m_bound = { 0, 0, w, h };
	}

	Sprite::Sprite() : m_Glyphs(nullptr), m_Colours(nullptr), m_width(0), m_height(0)
	{

	}

	Sprite::Sprite(int w, int h)
	{
		Create(w, h);
	}

	Sprite::Sprite(std::wstring linkFile) :m_Glyphs(nullptr), m_Colours(nullptr)
	{
		if (!Load(linkFile))
			Create(8, 8);
	}

	Sprite::Sprite(const Sprite& spr)
	{
		if (m_Glyphs != nullptr)
		{
			delete[] m_Glyphs;
			delete[] m_Colours;
			m_Glyphs = m_Colours = nullptr;
		}

		m_width = spr.getWidth();
		m_height = spr.getHeight();
		
		int size = spr.getWidth() * spr.getHeight();
		m_Glyphs = new short[size];
		m_Colours = new short[size];
		
		std::memcpy(m_Glyphs, spr.m_Glyphs, size);
		std::memcpy(m_Colours, spr.m_Colours, size);
	}

	Sprite::~Sprite()
	{
		delete[] m_Glyphs;
		delete[] m_Colours;
		m_Glyphs = m_Colours = nullptr;
	}

	short Sprite::getGlyph(int x, int y) const
	{
		if (x < 0 || x >= m_width || y < 0 || y >= m_height)
			return L' ';

		return m_Glyphs[m_width * y + x];
	}

	short Sprite::getColour(int x, int y) const
	{
		if (x < 0 || x >= m_width || y < 0 || y >= m_height)
			return FG_BLACK;

		return m_Colours[m_width * y + x];
	}

	void Sprite::setGlyph(int x, int y, short ch)
	{
		if (x < 0 || x >= m_width || y < 0 || y >= m_height)
			return;

		m_Glyphs[m_width * y + x] = ch;
	}

	void Sprite::setColour(int x, int y, short col)
	{
		if (x < 0 || x >= m_width || y < 0 || y >= m_height)
			return;

		m_Colours[m_width * y + x] = col;
	}

	int Sprite::getWidth() const
	{
		return m_width;
	}

	int Sprite::getHeight() const
	{
		return m_height;
	}


	const RectInt Sprite::getLocalBound() const
	{
		return m_bound;
	}

	const RectInt Sprite::getGlobalBound() const
	{
		RectInt rect = { m_position.x, m_position.y, m_width, m_height };
		return rect;
	}

	void Sprite::insert(const Sprite* spr)
	{
		if (spr == nullptr || this->m_Glyphs == nullptr)
			return;

		for (int y = 0; y < spr->m_height; y++)
		{
			for (int x = 0; x < spr->m_width; x++)
			{
				if (spr->getGlyph(x, y) != L' ')
				{
					setGlyph(x + spr->m_position.x, y + spr->m_position.y, spr->getGlyph(x, y));
					setColour(x + spr->m_position.x, y + spr->m_position.y, spr->getColour(x, y));
				}
			}
		}
	}

	bool Sprite::Save(std::wstring linkFile)
	{
		FILE* f = nullptr;
		_wfopen_s(&f, linkFile.c_str(), L"wb");
		if (f == nullptr)
			return false;

		std::fwrite(&m_width, sizeof(int), 1, f);
		std::fwrite(&m_height, sizeof(int), 1, f);
		std::fwrite(m_Glyphs, sizeof(short), m_width * m_height, f);
		std::fwrite(m_Colours, sizeof(short), m_width * m_height, f);

		std::fclose(f);

		return true;
	}

	bool Sprite::Load(std::wstring linkFile)
	{
		if (m_Glyphs != nullptr)  delete[] m_Glyphs;
		if (m_Colours != nullptr) delete[] m_Colours;
		m_Glyphs = m_Colours = nullptr;

		m_width = 0;
		m_height = 0;

		FILE* f = nullptr;
		_wfopen_s(&f, linkFile.c_str(), L"rb");

		if (f == nullptr)
			return false;

		std::fread(&m_width, sizeof(int), 1, f);
		std::fread(&m_height, sizeof(int), 1, f);

		Create(m_width, m_height);

		std::fread(m_Glyphs, sizeof(short), m_width * m_height, f);
		std::fread(m_Colours, sizeof(short), m_width * m_height, f);

		std::fclose(f);

		return true;
	}

	const Sprite& Sprite::operator=(const Sprite& spr)
	{
		if (m_Glyphs != nullptr)
		{
			delete[] m_Glyphs;
			delete[] m_Colours;
			m_Glyphs = m_Colours = nullptr;
		}

		m_width = spr.getWidth();
		m_height = spr.getHeight();
		
		int size = spr.getWidth() * spr.getHeight();
		m_Glyphs = new short[size];
		m_Colours = new short[size];

		std::memcpy(m_Glyphs, spr.m_Glyphs, size);
		std::memcpy(m_Colours, spr.m_Colours, size);

		return *this;
	}

	void Sprite::draw(ndmtEngine* target) const
	{
		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{
				if (m_Glyphs[y * m_width + x] != L' ')
					target->drawPoint(x + m_position.x, y + m_position.y,
						m_Glyphs[y * m_width + x], m_Colours[y * m_width + x]);
			}
		}
	}
}

