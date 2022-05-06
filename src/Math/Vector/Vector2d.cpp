#include "Vector2d.hpp"

#include <math.h>

namespace ss0glib::Math::Vector {
    Direction2d::Direction2d()
    {
        theta = NAN;
    };
    Direction2d::Direction2d(double t)
    {
        theta = t;
    };
    Direction2d::~Direction2d() {};

    Direction2d Direction2d::operator+(Direction2d& const d)
    {
        return Direction2d(this->theta + d.theta);
    }

    double Vector2d::CalculateMagnitude()
    {
        return sqrt(pow(mX, 2) + pow(mY, 2));
    }
    DirectionBase Vector2d::CalculateDirection()
    {
        return Direction2d(atan2(mY, mX));
    }

    Vector2d::Vector2d()
    {
        mX = 0;
        mY = 0;
        mMagnitude = 0;
        mDirection = Direction2d();
    }

    Vector2d::Vector2d(double x, double y)
    {
        mX = x;
        mY = y;
        mMagnitude = CalculateMagnitude();
        mDirection = CalculateDirection();
    }

    Vector2d::Vector2d(double magnitude, Direction2d direction)
    {
        mX = magnitude * cos(direction.theta);
        mY = magnitude * sin(direction.theta);
        mMagnitude = magnitude;
        mDirection = direction;
    }

    Vector2d::~Vector2d() {};

    double Vector2d::GetX()
    {
        return mX;
    }

    double Vector2d::GetY()
    {
        return mY;
    }

    Vector2d Vector2d::operator+(Vector2d& const v)
    { // TODO: add more operators (+= especially)
        return Vector2d(this->mX + v.mX, this->mY + v.mY);
    }

    Vector2d Vector2d::Zero()
    {
        return Vector2d(0, 0);
    }

    Vector2d Vector2d::Dot(Vector2d& const v1, Vector2d& const v2)
    {
        return Vector2d(v1.mX * v2.mX, v1.mY * v2.mY);
    }

    Vector3d Vector2d::Cross(Vector2d& const v1, Vector2d& const v2)
    {
        return Vector3d(0, 0, v1.mX * v2.mY - v1.mY * v2.mX);
    }
    // TODO: add function to normalize vector
}