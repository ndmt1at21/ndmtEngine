#pragma once

#include "Graphics/Export.h"
#include "Graphics/Shape.h"
#include "System/Vector2.h"

namespace mt
{
	class ndmtEngine;

	class Triagle :public Shape
	{
	private:
		Vector2i m_v1;
		Vector2i m_v2;
		Vector2i m_v3;

	public:
		Triagle();
		Triagle(const Vector2i& v1, const Vector2i& v2, const Vector2i& v3);
		~Triagle();

		void setVertex(const Vector2i& v1, const Vector2i& v2, const Vector2i& v3);
		Vector2i getVertex1() const;
		Vector2i getVertex2() const;
		Vector2i getVertex3() const;

	protected:
		void draw(ndmtEngine* target) const;
		void fill(ndmtEngine* target) const;
	};
}

