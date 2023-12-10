#include <iostream>
#include <stdexcept>

#define CUSTOM_PRE_CONDITION(condition) \
    do { \
        if (!(condition)) { \
            throw std::runtime_error("Pre-condition failed: " #condition); \
        } \
    } while (0)

// Usage example
void someFunction(int nbComponents, Type formatType, ComponentUsage componentUsage)
{
    CUSTOM_PRE_CONDITION(nbComponents > 0);
    CUSTOM_PRE_CONDITION(formatType < Type::NbTypes);
    CUSTOM_PRE_CONDITION(componentUsage < ComponentUsage::NbUsages);

    // Function body
    std::cout << "Function executed successfully!" << std::endl;
}

int main()
{
    try
    {
        someFunction(5, Type::TypeA, ComponentUsage::Usage1);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
