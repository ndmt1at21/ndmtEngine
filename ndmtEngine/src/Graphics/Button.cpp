#include "pch.h"
#include "Graphics/Button.h"
#include "ndmtEngine.h"

namespace mt
{
	Button::Button(Drawable* drawObj)
	{
		if (dynamic_cast<Shape*>(drawObj))
		{
			m_shape = dynamic_cast<Shape*>(drawObj);
			m_spr = nullptr;
		}
		else if (dynamic_cast<Sprite*>(drawObj))
		{
			m_shape = nullptr;
			m_spr = dynamic_cast<Sprite*>(drawObj);
		}
	}

	Button::~Button()
	{
	
	}

	void Button::setColor(const mt::Vector2i& colorSrc_Change)
	{
		m_color = colorSrc_Change;
	}

	void Button::setPosition(const mt::Vector2i& position)
	{
		if (m_shape)	m_shape->setPosition(position);
		else if (m_spr) m_spr->setPosition(position);
	}

	bool Button::isClicked()
	{
		mt::Event event;
		if (isInside() && Event::isKeyPressed(mt::MC_LEFT))
			return true;

		return false;
	}

	bool Button::isInside()
	{
		mt::RectInt globalBound;
		mt::Event event;

		if (m_shape)
			globalBound = m_shape->getGlobalBound();
		else if (m_spr)
			globalBound = m_spr->getGlobalBound();

		mt::Vector2i mousePos = Event::getMousePosition();
		if (mousePos.x > globalBound.left && mousePos.x < globalBound.left + globalBound.width
			|| mousePos.y > globalBound.top && mousePos.y < globalBound.top + globalBound.height)
		{
			return true;
		}

		return false;
	}

	void Button::draw(ndmtEngine* target) const
	{
		if (m_shape)	target->draw(m_shape);
		else if (m_spr) target->draw(m_spr);
	}
}