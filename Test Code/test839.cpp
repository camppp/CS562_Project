#ifndef BKSGE_CORE_MATH_FWD_VECTOR2_FWD_HPP
#define BKSGE_CORE_MATH_FWD_VECTOR2_FWD_HPP

class Vector2
{
public:
    // Default constructor
    Vector2() : m_x(0), m_y(0) {}

    // Parameterized constructor
    Vector2(float x, float y) : m_x(x), m_y(y) {}

    // Addition operator
    Vector2 operator+(const Vector2& rhs) const
    {
        return Vector2(m_x + rhs.m_x, m_y + rhs.m_y);
    }

    // Subtraction operator
    Vector2 operator-(const Vector2& rhs) const
    {
        return Vector2(m_x - rhs.m_x, m_y - rhs.m_y);
    }

    // Scalar multiplication operator
    Vector2 operator*(float scalar) const
    {
        return Vector2(m_x * scalar, m_y * scalar);
    }

    // Dot product function
    float dot(const Vector2& rhs) const
    {
        return m_x * rhs.m_x + m_y * rhs.m_y;
    }

private:
    float m_x;
    float m_y;
};

#endif // BKSGE_CORE_MATH_FWD_VECTOR2_FWD_HPP
