#ifndef SS0GLIB_MATH_VECTOR_VECTOR2D_HPP
#define SS0GLIB_MATH_VECTOR_VECTOR2D_HPP

#include "VectorBase.hpp"
#include "Vector3d.hpp"

#include <math.h>

namespace ss0glib::Math::Vector
{
    typedef struct Direction2d : public DirectionBase
    {
        double theta;
        Direction2d()
        {
            theta = NAN;
        };
        Direction2d(double t)
        {
            theta = t;
        };
        ~Direction2d() {};
        Direction2d operator+(Direction2d& const d)
        { // TODO: implement more operators
            Direction2d res;
            res.theta = this->theta + d.theta;
            return res;
        }
    } Direction2d;
    
    class Vector2d : public VectorBase
    { // TODO: separate implementations from declarations in this entire file and in VectorBase (maybe also make them .hpp files?)
        private:
            double mX;
            double mY;
            
            double CalculateMagnitude()
            {
                return sqrt(pow(mX, 2) + pow(mY, 2));
            }
            
            DirectionBase CalculateDirection()
            {
                return Direction2d(atan2(mY, mX));
            }
        public:
            Vector2d()
            {
                mX = 0;
                mY = 0;
                mMagnitude = 0;
                mDirection = Direction2d();
            }
            
            Vector2d(double x, double y)
            {
                mX = x;
                mY = y;
                mMagnitude = CalculateMagnitude();
                mDirection = Direction2d(atan2(mY, mX));
            }
            
            Vector2d(double magnitude, Direction2d direction)
            {
                mX = magnitude * cos(direction.theta);
                mY = magnitude * sin(direction.theta);
                mMagnitude = magnitude;
                mDirection = direction;
            }

            ~Vector2d() {};

            double GetX()
            {
                return mX;
            }

            double GetY()
            {
                return mY;
            }

            Vector2d operator+(Vector2d& const v)
            { // TODO: add more operators
                Vector2d res = Vector2d(this->mX + v.mX, this->mY + v.mY);
                return res;
            }

            static Vector2d Zero()
            {
                return Vector2d(0, 0);
            }

            static Vector2d Dot(Vector2d& const v1, Vector2d& const v2)
            {
                return Vector2d(v1.mX * v2.mX, v1.mY * v2.mY);
            }

            static Vector3d Cross(Vector2d& const v1, Vector2d& const v2)
            {
                return Vector3d(0, 0, v1.mX * v2.mY - v1.mY * v2.mX);
            }
            // TODO: add function to normalize vector
    };
}

#endif
