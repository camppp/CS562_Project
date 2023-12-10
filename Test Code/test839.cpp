#include "Vector2.hpp"

// Default constructor
Vector2::Vector2()
    : m_x(0.0f), m_y(0.0f)
{
}

// Parameterized constructor
Vector2::Vector2(float x, float y)
    : m_x(x), m_y(y)
{
}

// Addition operator
Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(m_x + rhs.m_x, m_y + rhs.m_y);
}

// Subtraction operator
Vector2 Vector2::operator-(const Vector2& rhs) const
{
    return Vector2(m_x - rhs.m_x, m_y - rhs.m_y);
}

// Scalar multiplication operator
Vector2 Vector2::operator*(float scalar) const
{
    return Vector2(m_x * scalar, m_y * scalar);
}

// Dot product function
float Vector2::dot(const Vector2& rhs) const
{
    return (m_x * rhs.m_x) + (m_y * rhs.m_y);
}
