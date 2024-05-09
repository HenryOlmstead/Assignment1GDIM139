#pragma once

struct Vector3
{
    Vector3 operator-(const Vector3& rhs) const;
    Vector3 operator+(const Vector3& rhs) const;

    float x;
    float y;
    float z;
};