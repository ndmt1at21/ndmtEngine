#pragma once

template <class T>
Rect<T>::Rect() :left(0), top(0), width(0), height(0)
{

}

template <class T>
Rect<T>::Rect(T Left, T Top, T Width, T Height) :left(Left), top(Top), width(Width), height(Height)
{

}

template <class T>
Rect<T>::Rect(const Vector2<T>& position, const Vector2<T>& size)
{
    left = position.x;
    top = position.y;
    width = size.x;
    height = size.y;
}

template <class T>
Rect<T>::Rect(const Rect<T>& rect)
{
    left = rect.left;
    top = rect.top;
    width = rect.width;
    height = rect.height;
}

template <class T>
Rect<T> Rect<T>::operator=(const Rect<T>& rect)
{
    left = rect.left;
    top = rect.top;
    width = rect.width;
    height = rect.height;

    return *this;
}

template <class T>
inline const Vector2<T> Rect<T>::getPostion() const
{
    return Vector2<T>(left, top);
}

template <class T>
inline const Vector2<T> Rect<T>::getSize() const
{
    return Vector2<T>(width, height);
}

template <class T>
bool Rect<T>::interset(const Rect<T>& rect) const
{
    T left1 = this->left;
    T top1 = this->top;
    T right1 = this->left + this->width;
    T bottom1 = this->top + this->height;

    T left2 = rect.left;
    T top2 = rect.top;
    T right2 = rect.left + rect.width;
    T bottom2 = rect.top + rect.height;

    // Case 1: size object 1 < size object 2
    if (left1 > left2 && left1 < right2)
    {
        if (top1 > top2 && top1 < bottom2)
        {
            return true;
        }
    }

    if (left1 > left2 && left1 < right2)
    {
        if (bottom1 > top2 && bottom1 < bottom2)
        {
            return true;
        }
    }

    if (right1 > left2 && right1 < right2)
    {
        if (top1 > top2 && top1 < bottom2)
        {
            return true;
        }
    }

    if (right1 > left2 && right1 < right2)
    {
        if (bottom1 > top2 && bottom1 < bottom2)
        {
            return true;
        }
    }

    // Case 2: size object 1 < size object 2
    if (left2 > left1 && left2 < right1)
    {
        if (top2 > top1 && top2 < bottom1)
        {
            return true;
        }
    }

    if (left2 > left1 && left2 < right1)
    {
        if (bottom2 > top1 && bottom2 < bottom1)
        {
            return true;
        }
    }

    if (right2 > left1 && right2 < right1)
    {
        if (top2 > top1 && top2 < bottom1)
        {
            return true;
        }
    }

    if (right2 > left1 && right2 < right1)
    {
        if (bottom2 > top1 && bottom2 < bottom1)
        {
            return true;
        }
    }

    // Case 3: size object 1 = size object 2
    if (top1 == top2 && right1 == right2 && bottom1 == bottom2)
    {
        return true;
    }

    return false;
}

template <class T>
Rect<T> operator+(const Rect<T>& rect, const Vector2<T> pos)
{
    Rect<T> rectTmp = rect;
    rectTmp.left += pos.x;
    rectTmp.top += pos.y;

    return rectTmp;
}
