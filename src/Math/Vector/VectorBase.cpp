#include "VectorBase.hpp"

namespace ss0glib::Math::Vector {
    DirectionBase::DirectionBase() {};
    DirectionBase::~DirectionBase() {};

    VectorBase::VectorBase() {};
    VectorBase::~VectorBase() {};

    double VectorBase::CalculateMagnitude() {};
    DirectionBase VectorBase::CalculateDirection() {};

    double VectorBase::GetMagnitude()
    {
        return mMagnitude;
    };
    DirectionBase VectorBase::GetDirection()
    {
        return mDirection;
    }
}