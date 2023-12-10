#include <iostream>

#define SAFE_RELEASE(p) if (p) { delete p; p = nullptr; }

void manageResource(void* resource) {
    SAFE_RELEASE(resource);
}

int main() {
    // Example usage
    int* lpTexture = new int(10);
    std::cout << "Before releasing: " << *lpTexture << std::endl;

    manageResource(lpTexture);

    if (lpTexture == nullptr) {
        std::cout << "Resource released successfully." << std::endl;
    } else {
        std::cout << "Resource release failed." << std::endl;
    }

    return 0;
}
