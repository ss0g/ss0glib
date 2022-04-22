#ifndef SS0GLIB_MATH_VECTOR_ABSTRACTVECTOR_HPP
#define SS0GLIB_MATH_VECTOR_ABSTRACTVECTOR_HPP

namespace ss0glib::Math::Vector
{
    typedef struct DirectionBase
    {
        DirectionBase() {};
        ~DirectionBase() {};
    } DirectionBase;
    
    class VectorBase
    {
        protected:
            VectorBase() {};
            ~VectorBase() {};
            
            double mMagnitude;
            DirectionBase mDirection;
            
            ///
            /// Should be called in constructor.
            ///
            virtual double CalculateMagnitude() {};
        public:
            double GetMagnitude()
            {
                return mMagnitude;
            };

            DirectionBase GetDirection()
            {
                return mDirection;
            }
    };
}

#endif
