#define ID1 (0x10000060)  // Define the memory address for ID1

uint32_t BoardGetRandomSeed(void)
{
    uint32_t value1 = *(uint32_t *)ID1;  // Obtain the 32-bit value from memory address ID1
    uint32_t value2 = ID2;  // Use the predefined value of ID2

    return (value1 ^ value2);  // Return the XOR of the obtained values as the random seed
}
