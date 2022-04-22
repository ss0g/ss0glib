#ifndef SS0GLIB_MATH_VECTOR_VECTOR3D_HPP
#define SS0GLIB_MATH_VECTOR_VECTOR3D_HPP

#include "AbstractVector.hpp"

#include <math.h>

namespace ss0glib::Math::Vector
{
    typedef struct Direction3d : public AbstractDirection
    {
        double theta;
        double phi;
        
        Direction3d()
        {
            theta = NAN;
            phi = NAN;
        };
        
        Direction3d(double t, double p)
        {
            theta = t;
            phi = p;
        };
        
        ~Direction3d() {};
        
        Direction3d operator+(Direction3d& const d)
        { // idk if this is correct, i'm not very familiar with spherical coordinates / 3d trig
            Direction3d res;
            res.theta = this->theta + d.theta;
            res.phi = this->phi + d.phi;
            return res;
        }
    } Direction3d;

    class Vector3d : public AbstractVector
    { // TODO: make a public way to get all private members
        private:
            double mX;
            double mY;
            double mZ;
            
            double mMagnitude;
            Direction3d mDirection;

            double CalculateMagnitude()
            {
                return sqrt(pow(mX, 2) + pow(mY, 2) + pow(mZ, 2));
            }

            Direction3d CalculateDirection()
            { // don't know if this phi is correct
                return Direction3d(atan2(mY, mX), atan2(mZ, sqrt(pow(mX, 2) + pow(mY, 2)))); // TODO: check if phi is correct
            }

        public:
            Vector3d()
            {
                mX = 0;
                mY = 0;
                mZ = 0;
                mMagnitude = 0;
                mDirection = Direction3d();
            }

            Vector3d(double x, double y, double z)
            {
                mX = x;
                mY = y;
                mZ = z;
                mMagnitude = CalculateMagnitude();
                mDirection = CalculateDirection();
            }

            Vector3d(double magnitude, Direction3d direction)
            {
                mX = magnitude * cos(direction.theta) * cos(direction.phi);
                mY = magnitude * sin(direction.theta) * cos(direction.phi);
                mZ = magnitude * sin(direction.phi); // woah, i think these values are correct
                mMagnitude = magnitude;
                mDirection = direction;
            }

            Vector3d operator+(Vector3d& const v) // TODO: add += and stuff
            {
                Vector3d res = Vector3d(this->mX + v.mX, this->mY + v.mY, this->mZ + v.mZ);
                return res;
            }

            static Vector3d Zero()
            {
                return Vector3d(0, 0, 0);
            }

            static Vector3d Dot(Vector3d& const v1, Vector3d& const v2)
            {
                return Vector3d(v1.mX * v2.mX, v1.mY * v2.mY, v1.mZ * v2.mZ);
            }

            static Vector3d Cross(Vector3d& const v1, Vector3d& const v2)
            {
                return Vector3d(v1.mY * v2.mZ - v1.mZ * v2.mY, v1.mZ * v2.mX - v1.mX * v2.mZ, v1.mX * v2.mY - v1.mY * v2.mX);
            }
    };
}

#endif
