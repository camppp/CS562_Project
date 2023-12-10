#include "Wm4FoundationPCH.h"
#include "Wm4DistVector3Rectangle3.h"
#include "Wm4Vector3.h"
#include "Wm4Matrix3.h"
#include "Wm4Plane3.h"
#include "Wm4Line3.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

template <class Real>
DistVector3Rectangle3<Real>::DistVector3Rectangle3 (const Vector3<Real>& rkPoint, const Vector3<Real>& rkCenter, const Vector3<Real>& rkAxis0, const Vector3<Real>& rkAxis1, const Vector3<Real>& rkAxis2, Real fExtent0, Real fExtent1, Real fExtent2)
    :
    m_kPoint(rkPoint),
    m_kCenter(rkCenter),
    m_kAxis0(rkAxis0),
    m_kAxis1(rkAxis1),
    m_kAxis2(rkAxis2),
    m_fExtent0(fExtent0),
    m_fExtent1(fExtent1),
    m_fExtent2(fExtent2)
{
}

template <class Real>
Real DistVector3Rectangle3<Real>::Get (void)
{
    // Compute coordinates of point with respect to rectangle.
    Real fS0 = GetRectangleCoordinate(3, &m_kPoint);
    Real fS1 = GetRectangleCoordinate(3, &m_kCenter);
    Real fS2 = GetRectangleCoordinate(3, &m_kAxis0);
    Real fS3 = GetRectangleCoordinate(3, &m_kAxis1);
    Real fS4 = GetRectangleCoordinate(3, &m_kAxis2);

    // Compute squared distance to each face of the rectangle.
    Real fSqrDist = (Real)0.0;
    for (int i = 0; i < 3; i++)
    {
        Real fSqrDistFace = GetSquared(3, &m_kPoint, &m_kCenter, &m_kAxis0, &m_kAxis1, &m_kAxis2, m_fExtent0, m_fExtent1, m_fExtent2);
        if (fSqrDistFace < fSqrDist)
        {
            fSqrDist = fSqrDistFace;
        }
    }

    // Compute squared distance to each edge of the rectangle.
    for (int i0 = 0; i0 < 3; i0++)
    {
        for (int i1 = i0 + 1; i1 < 3; i1++)
        {
            Real fSqrDistEdge = GetSquared(3, &m_kPoint, &m_kCenter, &m_kAxis0, &m_kAxis1, &m_kAxis2, m_fExtent0, m_fExtent1, m_fExtent2);
            if (fSqrDistEdge < fSqrDist)
            {
                fSqrDist = fSqrDistEdge;
            }
        }
    }

    // Compute squared distance to each vertex of the rectangle.
    for (int i = 0; i < 3; i++)
    {
        Real fSqrDistVertex = GetSquared(3, &m_kPoint, &m_kCenter, &m_kAxis0, &m_kAxis1, &m_kAxis2, m_fExtent0, m_fExtent1, m_fExtent2);
        if (fSqrDistVertex < fSqrDist)
        {
            fSqrDist = fSqrDistVertex;
        }
    }

    return Math<Real>::Sqrt(fSqrDist);
}

template <class Real>
Real DistVector3Rectangle3<Real>::GetSquared (void)
{
    // Compute coordinates of point with respect to rectangle.
    Real fS0 = GetRectangleCoordinate(3, &m_kPoint);
    Real fS1 = GetRectangleCoordinate(3, &m_kCenter);
    Real fS2 = GetRectangleCoordinate(3, &m_kAxis0);
    Real fS3 = GetRectangleCoordinate(3, &m_kAxis1);
    Real fS4 = GetRectangleCoordinate(3, &m_kAxis2);

    // Compute squared distance to each face of the rectangle.
    Real fSqrDist = (Real)0.0;
    for (int i = 0; i < 3; i++)
    {
        Real fSqrDistFace = GetSquared(3, &m_kPoint, &m_kCenter, &m_kAxis0, &m_kAxis1, &m_kAxis2, m_fExtent0, m_fExtent1, m_fExtent2);
        if (fSqrDistFace < fSqrDist)
        {
            fSqrDist = fSqrDistFace;
        }
    }

    // Compute squared distance to each edge of the rectangle.
    for (int i0 = 0; i0 < 3; i0++)
    {
        for (int i1 = i0 + 1; i1 < 3; i1++)
        {
            Real fSqrDistEdge = GetSquared(3, &m_kPoint, &m_kCenter, &m_kAxis0, &m_kAxis1, &m_kAxis2, m_fExtent0, m_fExtent1, m_fExtent2);
            if (fSqrDistEdge < fSqrDist)
            {
                fSqrDist = fSqrDistEdge;
            }
        }
    }

    // Compute squared distance to each vertex of the rectangle.
    for (int i = 0; i < 3; i++)
    {
        Real fSqrDistVertex = GetSquared(3, &m_kPoint, &m_kCenter, &m_kAxis0, &m_kAxis1, &m_kAxis2, m_fExtent0, m_fExtent1, m_fExtent2);
        if (fSqrDistVertex < fSqrDist)
        {
            fSqrDist = fSqrDistVertex;
        }
    }

    return fSqrDist;
}

template <class Real>
Real DistVector3Rectangle3<Real>::GetRectangleCoordinate (int iQuantity, const Vector3<Real>* akVertex)
{
    // Compute the coordinate of the point with respect to the rectangle.
    // The coordinate is a linear combination of the rectangle vertices.
    Real fCoord = (Real)0.0;
    for (int i = 0; i < iQuantity; i++)
    {
        fCoord += akVertex[i].Dot(m_kPoint - m_kCenter);
    }
    return fCoord;
}

template <class Real>
Real DistVector3Rectangle3<Real>::GetTriangleCoordinate (int iQuantity, const Vector3<Real>* akVertex)
{
    // Compute the coordinate of the point with respect to the triangle formed by the rectangle vertices.
    // The coordinate is a linear combination of the triangle vertices.
    Real fCoord = (Real)0.0;
    for (int i = 0; i < iQuantity; i++)
    {
        fCoord += akVertex[i].Dot(m_kPoint - m_kCenter);
    }
    return fCoord;
}

template <class Real>
Real DistVector3Rectangle3<Real>::GetLineCoordinate (int iQuantity, const Vector3<Real>* akVertex)
{
    // Compute the coordinate of the point with respect to the line formed by the rectangle vertices.
    // The coordinate is a linear combination of the line vertices.
    Real fCoord = (Real)0.0;
    for (int i = 0; i < iQuantity; i++)
    {
        fCoord += akVertex[i].Dot(m_kPoint - m_kCenter);
    }
    return fCoord;
}

template <class Real>
Real DistVector3Rectangle3<Real>::GetPlaneCoordinate (int iQuantity, const Vector3<Real>* akVertex)
{
    // Compute the coordinate of the point with respect to the plane formed by the rectangle vertices.
    // The coordinate is a linear combination of the plane vertices.
    Real fCoord = (Real)0.0;
    for (int i = 0; i < iQuantity; i++)
    {
        fCoord += akVertex[i].Dot(m_kPoint - m_kCenter);
    }
    return fCoord;
}

} // namespace Wm4
