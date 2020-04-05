#pragma once

namespace mt
{
    template <class T>
    class Rect
    {
    public:
        Rect();
        Rect(T Left, T Top, T Width, T Height);
        Rect(const Vector2<T>& position, const Vector2<T>& size);
        Rect(const Rect<T>& rect);

        Rect<T> operator=(const Rect<T>& rect);
        const Vector2<T> getPostion() const;
        const Vector2<T> getSize() const;
        bool interset(const Rect<T>& rect) const;

    public:
        // Member data
        T left;
        T top;
        T width;
        T height;
    };

    template <class T>
    Rect<T> operator+(const Rect<T>& rect, const Vector2<T> pos);

    #include "Graphics/Rect.inl"
    typedef Rect<int> RectInt;
    typedef Rect<float> RectFloat;
}

