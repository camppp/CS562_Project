// Sample usage of the CustomSharedPtr class
int main()
{
    CustomSharedPtr<int> ptr1(new int(5));
    CustomSharedPtr<int> ptr2 = ptr1; // Copy constructor called, reference count incremented

    std::cout << *ptr1 << std::endl;  // Output: 5
    std::cout << *ptr2 << std::endl;  // Output: 5

    *ptr1 = 10;
    std::cout << *ptr1 << std::endl;  // Output: 10
    std::cout << *ptr2 << std::endl;  // Output: 10

    return 0;  // Destructor called for ptr1 and ptr2, memory released
}
