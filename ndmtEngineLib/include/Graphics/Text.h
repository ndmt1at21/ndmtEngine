#pragma once

#include "Graphics/Export.h"
#include <string>
#include "Graphics/Drawable.h"
#include "Graphics/Transformable.h"

namespace mt
{
	class ndmtEngine;

	class Text :public Drawable, public Transformable
	{
	private:
		std::wstring m_str;
		short m_col;

	public:
		Text();
		Text(const std::wstring& str);
		Text(const Text& text);
		~Text();

		void setText(const std::wstring& str);
		void setColor(short col);

	protected:
		void draw(ndmtEngine* target);
	};
}

