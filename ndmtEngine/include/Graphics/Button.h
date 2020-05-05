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

	class NDMTENGINE_API Button :public Drawable
	{
	private:
		Sprite* m_spr;

	public:
		Button(Sprite* spr);
		~Button();

		bool isClicked() const;
		bool isInside() const;

	protected:
		void draw(ndmtEngine* target) const;
	};
}
