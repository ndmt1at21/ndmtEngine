template <class T>
inline Vector2<T>::Vector2() :x(0), y(0)
{

}

template <class T>
inline Vector2<T>::Vector2(T X, T Y) :x(X), y(Y)
{

}

template <class T>
template <class U>
inline Vector2<T>::Vector2(const Vector2<U>& vct)
{
	x = vct.x;
	y = vct.y;
}

template <class T>
inline Vector2<T>::~Vector2()
{

}

template <class T>
inline const Vector2<T>& Vector2<T>::operator=(const Vector2<T>& vct)
{
	this->x = vct.x;
	this->y = vct.y;

	return *this;
}

template <class T>
inline bool Vector2<T>::operator==(const Vector2<T>& vct)
{
	return (this->x == vct.x && this->y == vct.y);
}

template <class T>
inline bool Vector2<T>::operator!=(const Vector2<T>& vct)
{
	if (!(*this == vct))
		return true;

	return false;
}