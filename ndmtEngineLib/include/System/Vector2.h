#pragma once

namespace mt
{
	template <class T>
	class Vector2
	{
	public:
		Vector2();
		Vector2(T X, T Y);

		template <class U>
		Vector2(const Vector2<U>& vct);
		~Vector2();

		const Vector2<T>& operator=(const Vector2<T>& vct);
		bool operator==(const Vector2<T>& vct);
		bool operator!=(const Vector2<T>& vct);

		//member data
		T x;
		T y;
	};

	#include "System/Vector2.inl"
	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
}