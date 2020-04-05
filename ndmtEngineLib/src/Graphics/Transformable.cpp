#include "pch.h"
#include "Graphics/Transformable.h"

namespace mt
{
	Transformable::Transformable()
	{
		m_position.x = m_position.y = 0;
	}

	Transformable::~Transformable()
	{

	}

	void Transformable::setPosition(const Vector2i& pos)
	{
		m_position = pos;
	}

	const Vector2i& Transformable::getPosition()
	{
		return m_position;
	}
}

