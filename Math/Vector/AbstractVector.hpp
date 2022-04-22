#ifndef SS0GLIB_MATH_VECTOR_ABSTRACTVECTOR_HPP
#define SS0GLIB_MATH_VECTOR_ABSTRACTVECTOR_HPP

namespace ss0glib::Math::Vector {
    typedef struct AbstractDirection {
        AbstractDirection() {};
        virtual ~AbstractDirection() = 0;
    } AbstractDirection;
    
    class AbstractVector {
        protected:
            double mMagnitude;
            
            ///
            /// Should be called in constructor.
            ///
            virtual double CalculateMagnitude() = 0;
        public:
            double GetMagnitude() {
                return mMagnitude;
            };
    };
}

#endif
