#pragma once

#include "Graphics/Export.h"
#include "Graphics/Drawable.h"
#include "Graphics/Transformable.h"
#include "Graphics/Color.h"
#include "Graphics/PixelType.h"
#include "Graphics/Rect.h"
#include <string>

namespace mt
{
	class ndmtEngine;

	class Sprite :public Drawable, public Transformable
	{
	private:
		short* m_Glyphs = nullptr;
		short* m_Colours = nullptr;
		int m_width;
		int m_height;
		RectInt m_bound;
	
	public:
		Sprite();
		Sprite(int w, int h);
		Sprite(std::wstring linkFile);
		virtual ~Sprite();

	public:
		short getGlyph(int x, int y);
		void setGlyph(int x, int y, short ch);

		short getColour(int x, int y);
		void setColour(int x, int y, short col);

		int getWidth();
		int getHeight();

		const RectInt getLocalBound();
		const RectInt getGlobalBound();

		bool Save(std::wstring linkFile);
		bool Load(std::wstring linkFile);

	protected:
		void draw(ndmtEngine* target);
		void Create(int w, int h);
	};
}

