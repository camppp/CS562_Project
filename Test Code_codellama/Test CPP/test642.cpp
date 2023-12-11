#ifndef TVECTOR2_FUNC_HPP
#define TVECTOR2_FUNC_HPP

#include <cmath>

#ifdef RM_MATH_STAT
#include <profiler.h>
#endif

class TVector2 {
public:
    TVector2();
    TVector2(float x, float y);

    float x() const;
    float y() const;

    TVector2& operator+=(const TVector2& other);
    TVector2& operator-=(const TVector2& other);
    TVector2& operator*=(const TVector2& other);
    TVector2& operator/=(const TVector2& other);

    TVector2 operator+(const TVector2& other) const;
    TVector2 operator-(const TVector2& other) const;
    TVector2 operator*(const TVector2& other) const;
    TVector2 operator/(const TVector2& other) const;

    float dot(const TVector2& other) const;
    float cross(const TVector2& other) const;
    float magnitude() const;
    TVector2 normalize() const;

#ifdef RM_MATH_STAT
    static void profile_add(const TVector2& a, const TVector2& b);
    static void profile_sub(const TVector2& a, const TVector2& b);
    static void profile_mul(const TVector2& a, const TVector2& b);
    static void profile_div(const TVector2& a, const TVector2& b);
    static void profile_dot(const TVector2& a, const TVector2& b);
    static void profile_cross(const TVector2& a, const TVector2& b);
    static void profile_magnitude(const TVector2& a);
    static void profile_normalize(const TVector2& a);
#endif
};

#endif // TVECTOR2_FUNC_HPP
