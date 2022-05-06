#ifndef SS0GLIB_MATH_VECTOR_VECTORBASE_HPP
#define SS0GLIB_MATH_VECTOR_VECTORBASE_HPP

namespace ss0glib::Math::Vector
{
    typedef struct DirectionBase
    {
        protected:
            DirectionBase();
            ~DirectionBase();
            friend class VectorBase;
    } DirectionBase;
    
    class VectorBase
    {
        protected:
            VectorBase();
            ~VectorBase();
            
            double mMagnitude;
            DirectionBase mDirection;
            
            ///
            /// Should be called in constructor.
            ///
            virtual double CalculateMagnitude();
            virtual DirectionBase CalculateDirection();
        public:
            double GetMagnitude();

            DirectionBase GetDirection();
    };
}

#endif
