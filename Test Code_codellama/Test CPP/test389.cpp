#include <iostream>

// Define the custom data type
struct MyDataType {
    int a;
    int b;
};

// Define the function to initialize the variables
MyDataType stobi(int a, int b) {
    return MyDataType{a, b};
}

int main() {
    // Initialize the variables using the function
    MyDataType myData = stobi(1, 2);

    // Use the CHECK macro to assert a condition
    CHECK(myData.a == 1 && myData.b == 2);

    // Print the values of the variables
    std::cout << "a = " << myData.a << std::endl;
    std::cout << "b = " << myData.b << std::endl;

    return 0;
}
