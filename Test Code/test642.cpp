#ifndef RMVECTORMATH_TVECTOR2_FUNC_HPP_H
#define RMVECTORMATH_TVECTOR2_FUNC_HPP_H

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

#include <cmath>

template <typename T>
struct Vector2 {
    T x, y;
};

template <typename T>
Vector2<T> operator+(const Vector2<T>& v1, const Vector2<T>& v2) {
#ifdef RM_MATH_STAT
    PROFILE_FUNCTION();
#endif
    return {v1.x + v2.x, v1.y + v2.y};
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& v1, const Vector2<T>& v2) {
#ifdef RM_MATH_STAT
    PROFILE_FUNCTION();
#endif
    return {v1.x - v2.x, v1.y - v2.y};
}

template <typename T>
T dotProduct(const Vector2<T>& v1, const Vector2<T>& v2) {
#ifdef RM_MATH_STAT
    PROFILE_FUNCTION();
#endif
    return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
T crossProduct(const Vector2<T>& v1, const Vector2<T>& v2) {
#ifdef RM_MATH_STAT
    PROFILE_FUNCTION();
#endif
    return v1.x * v2.y - v1.y * v2.x;
}

template <typename T>
Vector2<T> normalize(const Vector2<T>& v) {
#ifdef RM_MATH_STAT
    PROFILE_FUNCTION();
#endif
    T magnitude = std::sqrt(v.x * v.x + v.y * v.y);
    return {v.x / magnitude, v.y / magnitude};
}

template <typename T>
T magnitude(const Vector2<T>& v) {
#ifdef RM_MATH_STAT
    PROFILE_FUNCTION();
#endif
    return std::sqrt(v.x * v.x + v.y * v.y);
}

#endif // RMVECTORMATH_TVECTOR2_FUNC_HPP_H
