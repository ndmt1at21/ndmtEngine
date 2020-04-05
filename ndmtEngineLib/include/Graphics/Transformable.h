#pragma once

#include "Graphics/Export.h"
#include "System/Vector2.h"

namespace mt
{
	class Transformable
	{
	public:
		Transformable();
		virtual ~Transformable();

		void setPosition(const Vector2i& pos);
		const Vector2i& getPosition();

	protected:
		Vector2i m_position;
	};
}
