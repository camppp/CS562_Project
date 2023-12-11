class AABB3
{
public:
    Vector3 Min;
    Vector3 Max;

    FORCEINLINE bool IsEverything() const { return Min.IsNegativeInfinity() && Max.IsPositiveInfinity(); }
    FORCEINLINE bool IsNothing() const { return Min.IsNaN() || Max.IsNaN(); }
    FORCEINLINE bool IsPoint() const { return Min == Max; }

    FORCEINLINE Vector3 PointCenter() const { return (Min + Max) * 0.5f; }
    FORCEINLINE Vector3 Size() const { return (Max - Min); }
    FORCEINLINE Vector3 HalfSize() const { return (Max - Min) * 0.5f; }
};
