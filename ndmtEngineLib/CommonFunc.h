#pragma once
#include <vector>

namespace mt
{
	template <class T>
	T maxArr(const std::vector<T>& vct, bool (*pFunc)(T x, T y))
	{
		if (vct.size() == 0)
			return -SIZE_MAX(T);

		T max = vct[0];
		for (int i = 0; i < (int)vct.size(); i++)
		{
			if (pFunc(vct[i], max))
				max = vct[i];
		}

		return max;
	}

	template <class T, class U>
	T minArr(const std::vector<T>& vct, bool (*pFunc)(T x, T y))
	{
		if (vct.size() == 0)
			return -SIZE_MAX(T);

		T min = vct[0];
		for (int i = 0; i < (int)vct.size(); i++)
		{
			if (pFunc(vct[i], min))
				min = vct[i];
		}

		return min;
	}
}
