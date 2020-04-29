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

	class NDMTENGINE_API Sprite :public Drawable, public Transformable
	{
	private:
		short* m_Glyphs;
		short* m_Colours;
		int m_width;
		int m_height;
		RectInt m_bound;
	
	public:
		Sprite();
		Sprite(int w, int h);
		Sprite(std::wstring linkFile);
		Sprite(const Sprite& spr);

		virtual ~Sprite();

	public:
		short getGlyph(int x, int y) const;
		void setGlyph(int x, int y, short ch);

		short getColour(int x, int y) const;
		void setColour(int x, int y, short col);

		int getWidth() const;
		int getHeight() const;

		const RectInt getLocalBound() const;
		const RectInt getGlobalBound() const;

		void insert(const Sprite* spr);

		bool Save(std::wstring linkFile);
		bool Load(std::wstring linkFile);

		const Sprite& operator=(const Sprite& spr);

	protected:
		void draw(ndmtEngine* target) const;
		void Create(int w, int h);

	};
}

