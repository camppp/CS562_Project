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
    // Store the Pitch, Yaw, and Roll values in little-endian format
    memcpy(byteArray, &rotator.Pitch, sizeof(float));
    memcpy(byteArray + sizeof(float), &rotator.Yaw, sizeof(float));
    memcpy(byteArray + 2 * sizeof(float), &rotator.Roll, sizeof(float));
}

// Function to convert byte array to FRotator
FRotator ByteArrayToFRotator(const unsigned char* byteArray)
{
    // Read the Pitch, Yaw, and Roll values from the byte array
    float pitch, yaw, roll;
    memcpy(&pitch, byteArray, sizeof(float));
    memcpy(&yaw, byteArray + sizeof(float), sizeof(float));
    memcpy(&roll, byteArray + 2 * sizeof(float), sizeof(float));

    // Return the reconstructed FRotator object
    return FRotator{pitch, yaw, roll};
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
