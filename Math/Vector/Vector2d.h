#include "AbstractVector.h"

#include <math.h>

namespace ss0glib::Math::Vector {
    typedef struct Direction2d : public AbstractDirection {
        double theta;
        Direction2d() {
            theta = NAN;
        };
        Direction2d(double t) {
            theta = t;
        };
        ~Direction2d() {};
        Direction2d operator+(Direction2d& const d) { // TODO: implement more operators
            Direction2d res;
            res.theta = this->theta + d.theta;
            return res;
        }
    } Direction2d;
    
    class Vector2d : AbstractVector { // TODO: separate implementations from declarations in this entire file and in AbstractVector (maybe also make them .hpp files?)
        private:
            double mX;
            double mY;
            double mMagnitude;
            Direction2d mDirection;
            double CalculateMagnitude() {
                return sqrt(pow(mX, 2) + pow(mY, 2));
            }
            Direction2d CalculateDirection() {
                return Direction2d(atan2(mY, mX));
            }
        public:
            Vector2d() {
                mX = 0;
                mY = 0;
                mMagnitude = 0;
                mDirection.theta = NAN;
            }
            Vector2d(double x, double y) {
                mX = x;
                mY = y;
                mMagnitude = CalculateMagnitude();
                mDirection.theta = atan2(mY, mX);
            }
            Vector2d(double magnitude, Direction2d direction) {
                mX = magnitude * cos(direction.theta);
                mY = magnitude * sin(direction.theta);
                mMagnitude = magnitude;
                mDirection = direction;
            }

            Vector2d operator+(Vector2d& const v) { // TODO: add more operators
                Vector2d res = Vector2d(this->mX + v.mX, this->mY + v.mY);
                return res;
            }
    };
}