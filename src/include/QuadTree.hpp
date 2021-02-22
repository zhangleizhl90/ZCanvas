#pragma once

#include <cassert>
#include <algorithm>
#include <memory>
#include <type_traits>
#include <vector>
#include "Rect.hpp"

namespace doodle
{
    template<typename T, typename GetRect, typename Equal = std::equal_to<T>, typename Float = float>
    class QuadTree
    {
        static_assert(std::is_convertible_v<std::invoke_result_t<GetRect, const T&>, Rect<Float>,
            "GetRect must be a callable of signature Rect<Float>(Const Float &)");
        static_assert(std::is_convertible_v<std::invoke_result_t<Equal, const T&, const T&>, bool>,
            "Equal must be a callable of signature bool(const T&, const T&)");
        static_assert(std::is_arithmetic_v<Float>);
    public:
        QuadTree(const Rect<Float>& rect, const GetRect& getRect = GetRect(),
            const Equal& equal = Equal()) :
            mRect(rect), mRoot(std::make_unique<Node>()), mGetRect(getRect), mEqual(equal)
        {

        }

    private:
        static constexpr auto THRESHOLD = std::size_t(16);

    };
}