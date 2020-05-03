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

	void Button::setFillAtrribute(const mt::Vector2i& gly_color)
	{
		if (m_shape) m_shape->setFillAttribute(gly_color);
	}

	void Button::setText(const Text& text, short col)
	{
		m_text = text;
		m_text.setColor(col);
	}

	void Button::setPosition(const mt::Vector2i& position)
	{
		RectInt rect;
		if (m_shape)
		{
			m_shape->setPosition(position);
			rect = m_shape->getGlobalBound();
		}
		else if (m_spr)
		{
			m_spr->setPosition(position);
			rect = m_spr->getGlobalBound();
		}
		 
		m_text.setPosition(mt::Vector2i((rect.left + rect.width) / 2, (rect.top + rect.height) / 2));
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

		target->draw(&m_text);
	}
}