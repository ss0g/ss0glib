namespace ss0glib::Math::Vector {
    typedef struct AbstractDirection {
        AbstractDirection() {};
        virtual ~AbstractDirection() = 0;
    } AbstractDirection;
    
    class AbstractVector {
        private:
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