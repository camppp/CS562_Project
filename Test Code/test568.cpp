namespace bolder { namespace math {
    class ComplexNumber {
    private:
        double real_;
        double imag_;

    public:
        ComplexNumber(double real, double imag) : real_(real), imag_(imag) {}

        ComplexNumber add(const ComplexNumber& other) const {
            return ComplexNumber(real_ + other.real_, imag_ + other.imag_);
        }

        ComplexNumber subtract(const ComplexNumber& other) const {
            return ComplexNumber(real_ - other.real_, imag_ - other.imag_);
        }

        ComplexNumber multiply(const ComplexNumber& other) const {
            double newReal = real_ * other.real_ - imag_ * other.imag_;
            double newImag = real_ * other.imag_ + imag_ * other.real_;
            return ComplexNumber(newReal, newImag);
        }

        ComplexNumber divide(const ComplexNumber& other) const {
            double denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
            double newReal = (real_ * other.real_ + imag_ * other.imag_) / denominator;
            double newImag = (imag_ * other.real_ - real_ * other.imag_) / denominator;
            return ComplexNumber(newReal, newImag);
        }

        double magnitude() const {
            return sqrt(real_ * real_ + imag_ * imag_);
        }

        double phase() const {
            return atan2(imag_, real_);
        }
    };
}}
