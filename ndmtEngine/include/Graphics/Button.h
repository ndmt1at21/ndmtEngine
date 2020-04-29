#pragma once
#include "Graphics/Export.h"
#include "Graphics/Drawable.h"
#include "Graphics/Shape.h"
#include "Graphics/Rect.h"
#include "Graphics/Circle.h"
#include "Graphics/Line.h"
#include "Graphics/Text.h"
#include "Graphics/Sprite.h"
#include "Graphics/Rect.h"
#include "System/Event.h"

namespace mt
{ 
	class ndmtEngine;

	class Button :public Drawable
	{
	private:
		Sprite* m_spr;
		Shape* m_shape;
		mt::Text m_text;
		mt::Vector2i m_color;

	public:
		Button(Drawable* drawObj);
		~Button();

		void setColor(const mt::Vector2i& colorSrc_Change);
		void setPosition(const mt::Vector2i& position);
		bool isClicked();
		bool isInside();

	protected:
		void draw(ndmtEngine* target) const;
	};
}
