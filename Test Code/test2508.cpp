FORCEINLINE bool AABB3::IsEverything() const { return Min.IsNegativeInfinity() && Max.IsPositiveInfinity(); }

FORCEINLINE bool AABB3::IsNothing() const { return Min.IsNaN() || Max.IsNaN(); }

FORCEINLINE bool AABB3::IsPoint() const { return Min == Max; }

FORCEINLINE Vector3 AABB3::PointCenter() const { return (Min + Max) * 0.5f; }

FORCEINLINE Vector3 AABB3::Size() const { return (Max - Min); }

FORCEINLINE Vector3 AABB3::HalfSize() const { return (Max - Min) * 0.5f; }
