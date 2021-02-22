#pragma once

#include "Point2D.hpp"

namespace doodle
{
    template <typename T>
    class Rect
    {
    public:
        T left;

        T top;
        /**
         * @brief 必须是正数
         * 
         */
        T width;

        /**
         * @brief 必须是正数
         * 
         */
        T height;

        constexpr Rect(T left = 0, T top = 0, T width = 0, T height = 0) noexcept :
            left(left), top(top), width(width), height(height)
        {
        }

        constexpr Rect(const Point2D<T>* position, const Point2D<T>& size) noexcept :
            left(position.x), top(position.y), width(size.x), height(size.y)
        {
        }

        constexpr T getRight() const noexcept
        {
            return left + width;
        }

        constexpr T getBottom() const noexcept
        {
            return top + height;
        }

        constexpr T getTop() const noexcept
        {
            return top;
        }

        constexpr T getLeft() const noexcept
        {
            return left;
        }

        constexpr Point2D<T> getTopLeft() const noexcept
        {
            return Point2D<T>(left, top);
        }

        constexpr Point2D<T> getCenter() const noexcept
        {
            return Point2D<T>(left + width / 2, top + height / 2);
        }

        constexpr Point2D<T> getSize() const noexcept
        {
            return Point2D<T>(width, height);
        }

        constexpr bool contains(const Rect<T>& rect) const noexcept
        {
            return left <= rect.left && box.getRight() <= getRight() && top < box.top && box.getBottom() <= getBottom();
        }
    };
}