#pragma once
#include <cstdint>
#include <cmath>

#include "Vector3.h"

#define UNUSED_ARG(arg) (void)arg

struct IAssignment2
{
    // Given a vector, return TRUE if the magnitude is exactly zero
    virtual bool IsVectorMagnitudeZero(const Vector3& vectorToTest) const = 0;

    // Given two circles represented as a center point and radius, return TRUE if they touch or overlap
    // Radius is guaranteed to be greater than or equal to zero
    virtual bool DoCirclesTouch(const Vector3& centerA, float radiusA, const Vector3& centerB, float radiusB) const = 0;

    // Given a player view matrix (forward, up, right) and a target, determine if the target is higher than the mid-point of the player view
    virtual bool IsTargetAboveMe(const Vector3& forward, const Vector3& up, const Vector3& right, const Vector3& target) const = 0;

    // Given three points of a triangle, calculate a NORMAL vector orthoganal to the triangle
    // Returned vector in this case can point in either possible direction
    // Return an empty vector (magnitude zero) for invalid inputs
    virtual Vector3 GetTriangleNormal(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC) const = 0;

    // Given three points of a triangle and a target point, get the distance the point is from the plane of the triangle
    virtual float GetDistanceFromTriangle(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC, const Vector3& target) const = 0;

    // Given a plane normal vector, reflect a vector off the plane as if it were a one-sided mirror
    virtual Vector3 Reflect(const Vector3& planeNormal, const Vector3& vectorToReflect) const = 0;

    // Given a plane represented by a point and normal vector, and a circle represented by center and radius
    // Radius is guaranteed to be greater than or equal to zero
    // Return TRUE if any part of the sphere is touching or inside (on the side depicted by the normal vector) the plane
    virtual bool IsSphereInsidePlane(const Vector3& ptOnPlane, const Vector3& planeNormal, const Vector3& circleCenter, float circleRadius) const = 0;
};
