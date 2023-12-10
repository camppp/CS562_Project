#include <iostream>
#include <cstdint>

enum class EOnlineKeyValuePairDataType
{
    Double,
    Float,
    Int32,
    Int64
};

class Variant
{
private:
    EOnlineKeyValuePairDataType type;
    double doubleValue;
    float floatValue;
    int32_t int32Value;
    int64_t int64Value;

public:
    void GetValue(double& value)
    {
        value = doubleValue;
    }

    void GetValue(float& value)
    {
        value = floatValue;
    }

    void GetValue(int32_t& value)
    {
        value = int32Value;
    }

    void GetValue(int64_t& value)
    {
        value = int64Value;
    }

    EOnlineKeyValuePairDataType GetType() const
    {
        return type;
    }
};

int64_t ConvertTo64BitInteger(const Variant& variant)
{
    EOnlineKeyValuePairDataType dataType = variant.GetType();

    switch (dataType)
    {
        case EOnlineKeyValuePairDataType::Double:
        {
            double doubleValue = 0.0;
            variant.GetValue(doubleValue);
            return static_cast<int64_t>(doubleValue);
        }
        case EOnlineKeyValuePairDataType::Float:
        {
            float floatValue = 0.0f;
            variant.GetValue(floatValue);
            return static_cast<int64_t>(floatValue);
        }
        case EOnlineKeyValuePairDataType::Int32:
        {
            int32_t int32Value = 0;
            variant.GetValue(int32Value);
            return static_cast<int64_t>(int32Value);
        }
        case EOnlineKeyValuePairDataType::Int64:
        {
            int64_t int64Value = 0;
            variant.GetValue(int64Value);
            return int64Value;
        }
        default:
            throw std::invalid_argument("Unsupported data type");
    }
}

int main()
{
    Variant variant;
    // Set the variant value and type here

    int64_t convertedValue = ConvertTo64BitInteger(variant);
    std::cout << "Converted value: " << convertedValue << std::endl;

    return 0;
}
