#include <boost/multiprecision/cpp_dec_float.hpp>

template<typename Precision, bool ExpressionTemplate>
class CustomPrecisionArithmetic
{
public:
    using PrecisionType = boost::multiprecision::cpp_dec_float<Precision>;

    CustomPrecisionArithmetic(PrecisionType precision, bool expressionTemplate)
        : precision(precision), expressionTemplate(expressionTemplate) {}

    PrecisionType add(PrecisionType a, PrecisionType b)
    {
        if (expressionTemplate)
        {
            return a + b;
        }
        else
        {
            return PrecisionType(a) + PrecisionType(b);
        }
    }

    PrecisionType subtract(PrecisionType a, PrecisionType b)
    {
        if (expressionTemplate)
        {
            return a - b;
        }
        else
        {
            return PrecisionType(a) - PrecisionType(b);
        }
    }

    PrecisionType multiply(PrecisionType a, PrecisionType b)
    {
        if (expressionTemplate)
        {
            return a * b;
        }
        else
        {
            return PrecisionType(a) * PrecisionType(b);
        }
    }

    PrecisionType divide(PrecisionType a, PrecisionType b)
    {
        if (expressionTemplate)
        {
            return a / b;
        }
        else
        {
            return PrecisionType(a) / PrecisionType(b);
        }
    }

private:
    PrecisionType precision;
    bool expressionTemplate;
};
