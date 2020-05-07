#include "pch.h"
#include "Graphics/Button.h"
#include "ndmtEngine.h"

namespace mt
{
	Button::Button(Sprite* spr)
	{
		m_spr = spr;
	}

	Button::~Button()
	{
	
	}

	bool Button::isClicked() const
	{
		mt::Event event;
		if (isInside() && Event::isKeyPressed(mt::MC_LEFT))
			return true;

		return false;
	}

	bool Button::isInside() const
	{
		mt::RectInt globalBound;
		mt::Event event;

		globalBound = m_spr->getGlobalBound();
		
		mt::Vector2i mousePos = Event::getMousePosition();
		if (mousePos.x > globalBound.left && mousePos.x < globalBound.left + globalBound.width
			&& mousePos.y > globalBound.top && mousePos.y < globalBound.top + globalBound.height)
		{
			return true;
		}

		return false;
	}

	void Button::draw(ndmtEngine* target) const
	{
		target->draw(m_spr);
	}
}