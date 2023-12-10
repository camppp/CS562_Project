#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct License {
    char key[20];
    char expirationDate[11]; // Format: YYYY-MM-DD
};

bool isExpired(const char* expirationDate) {
    struct tm expirationTime = {0};
    strptime(expirationDate, "%Y-%m-%d", &expirationTime); // Parse expiration date

    time_t currentTime = time(NULL);
    struct tm* currentLocalTime = localtime(&currentTime);

    if (mktime(&expirationTime) < mktime(currentLocalTime)) {
        return true; // Expiration date has passed
    } else {
        return false; // Expiration date has not passed
    }
}

int main() {
    // ... (same as in the problem description)

    return 0;
}
