#include "Assignment2StudentImpl.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

// This function takes a 3D vector as input and checks if its magnitude is zero or not.
// It returns a boolean value indicating whether the magnitude of the vector is zero or not.
// Students are expected to implement the logic to calculate the magnitude of the given vector and compare it with zero.
bool Assignment2StudentImpl::IsVectorMagnitudeZero(const Vector3& vectorToTest) const
{
    //If i think correctly, we need to take each value in the vector (x,y,z) and square them. Since the magnitude equals sqrt(x^2 + y^2 + z^2), if the sum of those squares is zero then 
    //The magnitude should also be zero.
    //Squaring them might be expensive (probably not i hope) but it gets around negative values (maybe i should use abs now that i think about it)
    float x_square = vectorToTest.x * vectorToTest.x;
    float y_square = vectorToTest.y * vectorToTest.y;
    float z_square = vectorToTest.z * vectorToTest.z;
    float sums = x_square +y_square + z_square ;

    if (sums == 0) {
        return true;
    }else {
        return false;
    }
}

// This function takes two circles as input, specified by their center points and radii, and checks if they are touching or not.
// It returns a boolean value indicating whether the circles are touching or not.
// Students are expected to implement the logic to check if the distance between the centers of the two circles touch or not.
bool Assignment2StudentImpl::DoCirclesTouch(const Vector3& centerA, float radiusA, const Vector3& centerB, float radiusB) const
{
    //Aight so we wanna know if the distance between centers is less than the sum of their radii. If its equal to the sum of the radii, the circles are tangential
    //We'll find out if thats important once we run the tests lol
    //WE first gotta find distance (scalar  i think) between the centers.
    //Not yet sure how to handle zero vectors atm, but we'll get to that

    //Ok so vector distance is (x1-x2) + (y1-y2) + (z1-z2) = dist^2
    float x_dist = centerA.x - centerB.x;
    float y_dist = centerA.y - centerB.y;
    float z_dist = centerA.z - centerB.z;
   // float dist_squared = x_dist + y_dist + z_dist;
    float d_squared = (x_dist * x_dist) + (y_dist * y_dist) + (z_dist * z_dist);

    //This is our distance squared, everybody (and their mom) hates square roots so we wont calculate those now

    float radii_combined = radiusA + radiusB;

    if (d_squared <= (radii_combined * radii_combined)) {
        return true;
    }
    else {
        return false;
    }
   
}

// This function takes in four 3D vectors as input: forward, up, right, and target.
// It determines whether the target point is above or below the calling object based on the orientation of the object.
// Students are expected to implement the logic to calculate the position of the target relative to the object based on its 
// forward, up, and right vectors.
// The function should return a boolean value indicating whether the target is above the object (true) or not (false).
bool Assignment2StudentImpl::IsTargetAboveMe(const Vector3& forward, const Vector3& up, const Vector3& right, const Vector3& target) const
{
    //I might be underthinking this but it should be true that I can do x1*x2, y1*y2 and z1*z2 to get the dot product
    //I assume I only want the forward vector, as that is which direction the player is looking (otherwise it'd be the backward vector)
    //Okay  should start reading the assingment more clearly,above =/= in front of, we want the Up vector duh

    float x_vals = up.x * target.x;
    float y_vals = up.y * target.y;
    float z_vals = up.z * target.z;
    float sum = x_vals + y_vals + z_vals;

    if (sum <= 0) {
        return false;
    }
    else {
        return true;
    }

    UNUSED_ARG(forward);
    UNUSED_ARG(up);
    UNUSED_ARG(right);
    UNUSED_ARG(target);

}

// This function takes three 3D points as input that represent the vertices of a triangle and calculates the normal vector of the triangle.
// It returns a Vector3 object representing the normal vector of the triangle.
// Students are expected to implement the logic to calculate the normal vector of the triangle using the provided input points.
Vector3 Assignment2StudentImpl::GetTriangleNormal(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC) const
{
    //Okay this one is less fun, but shouldn't be too bad
 
    //WE wanna take the cross product of two of this sides of this triangle, but we only have coordinate points.
    //To change that we gotta do our distance calculation from a few problems ago
    //Ok so vector distance is (x1-x2) + (y1-y2) + (z1-z2) = dist^2
   
    
    float x_dist = ptB.x - ptA.x;
    float y_dist = ptB.y - ptA.y;
    float z_dist = ptB.z - ptA.z;
    Vector3 A_Side;
    A_Side.x = x_dist;
    A_Side.y = y_dist;
    A_Side.z = z_dist;
    //First side of da triangle done

    float x2_dist = ptC.x - ptA.x;
    float y2_dist = ptC.y - ptA.y;
    float z2_dist = ptC.z - ptA.z;
    Vector3 B_Side;
    B_Side.x = x2_dist;
    B_Side.y = y2_dist;
    B_Side.z = z2_dist;
    //Second side of da triangle done


    //BRUHHHHHHHHH I forgot to normalize this silly little vector, so we gotta find the magnitude then divide each one by that magnitude BRUH
    //I think this should do it
    Vector3 Norman;
    Norman.x = (A_Side.y * B_Side.z) - (A_Side.z * B_Side.y);
    Norman.y = (A_Side.z * B_Side.x) - (A_Side.x * B_Side.z);
    Norman.z = (A_Side.x * B_Side.y) - (A_Side.y * B_Side.x);

    //BRUHHHHHHHHH I forgot to normalize this silly little vector, so we gotta find the magnitude then divide each one by that magnitude BRUH
    //I think this should do it
    //Note we can only normalize if the vector isnt the zero vector
    if (!IsVectorMagnitudeZero(Norman) ){
        float mag = sqrt((Norman.x * Norman.x) + (Norman.y * Norman.y) + (Norman.z * Norman.z));
            Norman.x = Norman.x / mag;
            Norman.y = Norman.y / mag;
            Norman.z = Norman.z / mag;
    }


   
    return Norman;

    // float dist_squared = x_dist + y_dist + z_dist;
    //float d_squared = (x_dist * x_dist) + (y_dist * y_dist) + (z_dist * z_dist);

    UNUSED_ARG(ptA);
    UNUSED_ARG(ptB);
    UNUSED_ARG(ptC);
    
}

// This function takes three points forming a triangle and a target point as input.
// It calculates and returns the minimum distance between the target point and the triangle.
// Students are expected to implement the logic to calculate the distance between the target point and the triangle using 
// the provided input.
float Assignment2StudentImpl::GetDistanceFromTriangle(const Vector3& ptA, const Vector3& ptB, const Vector3& ptC, const Vector3& target) const
{

    //Ok so actually what we wanna do is a PROJECTION, so we gotta get the magnitude of the triangle vectors and project the target onto them.

    float mag = (ptA.x * ptA.x) + (ptA.y * ptA.y) + (ptA.z * ptA.z);
        // X^2 + y^2 + z^2 = mag^2
    mag  = mag + 2;



    //What I think would be the fastest is to get each of the triangles edges as a vector (like we did in the last one)
    //And then determine the distance from Target to each of the sides and compare the distances,returning the shortest one.
    float x_dist = ptB.x - ptA.x;
    float y_dist = ptB.y - ptA.y;
    float z_dist = ptB.z - ptA.z;
    Vector3 A_Side;
    A_Side.x = x_dist;
    A_Side.y = y_dist;
    A_Side.z = z_dist;
    //First side of da triangle done

    float x2_dist = ptC.x - ptA.x;
    float y2_dist = ptC.y - ptA.y;
    float z2_dist = ptC.z - ptA.z;
    Vector3 B_Side;
    B_Side.x = x2_dist;
    B_Side.y = y2_dist;
    B_Side.z = z2_dist;
    //Second side of da triangle done

    float x3_dist = ptC.x - ptB.x;
    float y3_dist = ptC.y - ptB.y;
    float z3_dist = ptC.z - ptB.z;
    Vector3 C_Side;
    C_Side.x = x3_dist;
    C_Side.y = y3_dist;
    C_Side.z = z3_dist;
    //Last side of the triangle done.

    //Calculate distance from each vector
    //A VEctor
    float xA_dist = A_Side.x - target.x;
    float yA_dist = A_Side.y - target.y;
    float zA_dist = A_Side.z - target.z;
    // float dist_squared = x_dist + y_dist + z_dist;
    float A_distance = (xA_dist * xA_dist) + (yA_dist * yA_dist) + (zA_dist * zA_dist);

    //B Vector
    x_dist = B_Side.x - target.x;
    y_dist = B_Side.y - target.y;
    z_dist = B_Side.z - target.z;
    // float dist_squared = x_dist + y_dist + z_dist;
    float B_distance = (x_dist * x_dist) + (y_dist * y_dist) + (z_dist * z_dist);

    //C Vector
    x_dist = C_Side.x - target.x;
    y_dist = C_Side.y - target.y;
    z_dist = C_Side.z - target.z;
    // float dist_squared = x_dist + y_dist + z_dist;
    float C_distance = (x_dist * x_dist) + (y_dist * y_dist) + (z_dist * z_dist);

    std::cout << C_distance;
    std::cout << B_distance;
    std::cout << A_distance;

    float closest = std::min(A_distance, B_distance);
    closest = std::min(C_distance, closest);
    return closest;






    UNUSED_ARG(ptA);
    UNUSED_ARG(ptB);
    UNUSED_ARG(ptC);
    UNUSED_ARG(target);
 
}

// This function takes two 3D vectors as input: planeNormal and vectorToReflect.
// It calculates the reflection of vectorToReflect about the plane with planeNormal as its normal.
// The function returns a new vector which is the reflected vector.
// Students are expected to implement the logic to calculate the reflection of the given vector about the plane with 
// the given normal vector.
Vector3 Assignment2StudentImpl::Reflect(const Vector3& planeNormal, const Vector3& vectorToReflect) const
{
    //Using the formula r  = d-2(d*n)n whre N must be normal.
    Vector3 Normal;
    Normal.x = 0;
    Normal.y = 0;
    Normal.z = 0;
    if (!IsVectorMagnitudeZero(planeNormal)) {
        float mag = sqrt((planeNormal.x * planeNormal.x) + (planeNormal.y * planeNormal.y) + (planeNormal.z * planeNormal.z));
       
        Normal.x = planeNormal.x / mag;
        Normal.y = planeNormal.y / mag;
        Normal.z = planeNormal.z / mag;
        //Now it should be normal
    }
    Vector3 dproduct;
    dproduct.x = 2* (Normal.x * vectorToReflect.x);
    dproduct.y = 2* (Normal.y * vectorToReflect.y);
    dproduct.z = 2* (Normal.z * vectorToReflect.z);
    //dproduct should now be dot product of the two starting vectors * 2 

    //now we wanna calculate 2(d*n) * n, and we already have the first part.
    dproduct.x = Normal.x * dproduct.x;
    dproduct.y = Normal.y * dproduct.y;
    dproduct.z = Normal.z * dproduct.z;

    //Now we subtract it from D and we should arrive at our final answer
    Vector3 output;
    output.x = vectorToReflect.x - dproduct.x;
    output.y = vectorToReflect.y - dproduct.y;
    output.z = vectorToReflect.z - dproduct.z;
    return output;


    UNUSED_ARG(planeNormal);
    UNUSED_ARG(vectorToReflect);
 
}

// This function takes a point on a plane, a normal vector to the plane, a center point of a sphere and its radius as input.
// It checks if the sphere is completely inside the plane or not.
// Students are expected to implement the logic to check if all points on the surface of the sphere lie on the same side of the plane.
// If all points lie on the same side of the plane, the function should return true, otherwise false.
bool Assignment2StudentImpl::IsSphereInsidePlane(const Vector3& ptOnPlane, const Vector3& planeNormal, const Vector3& circleCenter, float circleRadius) const
{
    UNUSED_ARG(ptOnPlane);
    UNUSED_ARG(planeNormal);
    UNUSED_ARG(circleCenter);
    UNUSED_ARG(circleRadius);
    return false;
}
