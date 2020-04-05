#pragma once

#include "Graphics/Export.h"
#include <string>
#include "Graphics/Drawable.h"
#include "Graphics/Transformable.h"
#include <map>
#include "Graphics/Sprite.h"

namespace mt
{
	class ndmtEngine;

	class NDMTENGINE_API Text :public Drawable, public Transformable
	{
	private:
		std::wstring m_str;
		short m_col;
		int m_align;

		static std::wstring m_fontType;
		static std::map <int, Sprite*> m_font;

	public:
		Text();
		Text(const std::wstring& str, std::wstring m_fontType = L"default", int align = 0);
		Text(const Text& text);
		~Text();

		void setText(const std::wstring& str);
		void setColor(short col);
		void setFontType(std::wstring fontType = L"default");
		void setAlign(int align);

	protected:
		void draw(ndmtEngine* target) const;
	};
}

