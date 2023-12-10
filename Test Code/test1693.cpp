#include <iostream>
#include <cstring>

struct FRotator
{
    float Pitch;
    float Yaw;
    float Roll;
};

// Function to convert FRotator to byte array
void FRotatorToByteArray(const FRotator& rotator, unsigned char* byteArray)
{
    memcpy(byteArray, &rotator, sizeof(FRotator));
}

// Function to convert byte array to FRotator
FRotator ByteArrayToFRotator(const unsigned char* byteArray)
{
    FRotator rotator;
    memcpy(&rotator, byteArray, sizeof(FRotator));
    return rotator;
}

int main()
{
    FRotator originalRotator = {45.0f, 90.0f, 135.0f};
    unsigned char byteArray[sizeof(FRotator)];

    FRotatorToByteArray(originalRotator, byteArray);

    std::cout << "Byte array representation: ";
    for (int i = 0; i < sizeof(FRotator); ++i)
    {
        std::cout << std::hex << static_cast<int>(byteArray[i]) << " ";
    }
    std::cout << std::endl;

    FRotator reconstructedRotator = ByteArrayToFRotator(byteArray);

    std::cout << "Reconstructed FRotator: Pitch=" << reconstructedRotator.Pitch
              << ", Yaw=" << reconstructedRotator.Yaw
              << ", Roll=" << reconstructedRotator.Roll << std::endl;

    return 0;
}
