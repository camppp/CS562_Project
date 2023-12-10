#include <iostream>
#include <stdexcept>

class copy_not_implemented : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Masolas nincs implementalva!";
    }
};

int main()
{
    try
    {
        // Throw an instance of the copy_not_implemented exception
        throw copy_not_implemented();
    }
    catch (const copy_not_implemented& e)
    {
        // Print the error message
        std::cout << e.what() << std::endl;
    }

    return 0;
}
