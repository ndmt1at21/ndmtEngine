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

		void setFillAtrribute(const mt::Vector2i& gly_color);
		void setText(const Text& text, const Color& col);
		void setPosition(const mt::Vector2i& position);
		bool isClicked() const;
		bool isInside() const;

	protected:
		void draw(ndmtEngine* target) const;
	};
}
