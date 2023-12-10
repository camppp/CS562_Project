uint32_t BasicTypeTestServerImplExample::getULong(/*in*/ uint32_t ulo1, /*inout*/ uint32_t& ulo2, /*out*/ uint32_t& ulo3) 
{
    uint32_t returnedValue; // Declare a variable to store the returned value

    ulo3 = ulo2; // Set the value of ulo3 to the current value of ulo2

    returnedValue = ulo1; // Set the value of returnedValue to the initial value of ulo1

    ulo2 = ulo1 + ulo2; // Update the value of ulo2 by adding the initial values of ulo1 and ulo2

    return returnedValue; // Return the initial value of ulo1
}
