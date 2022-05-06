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
        Direction2d();
        Direction2d(double t);
        ~Direction2d();
        
        Direction2d operator+(Direction2d& const d);
    } Direction2d;
    
    class Vector2d : public VectorBase
    { // TODO: separate implementations from declarations in this entire file and in VectorBase (maybe also make them .hpp files?)
        private:
            double mX;
            double mY;
            
            double CalculateMagnitude();
            DirectionBase CalculateDirection();
        public:
            Vector2d();
            
            Vector2d(double x, double y);
            
            Vector2d(double magnitude, Direction2d direction);

            ~Vector2d();

            double GetX();

            double GetY();

            Vector2d operator+(Vector2d& const v);

            static Vector2d Zero();

            static Vector2d Dot(Vector2d& const v1, Vector2d& const v2);

            static Vector3d Cross(Vector2d& const v1, Vector2d& const v2);
    };
}

#endif
