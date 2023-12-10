#include <stdio.h>
#include <string.h>

typedef struct {
    char szTlsServerName[256];
    // Other fields representing the license pack
} LicPack;

char* processLicensePack(LicPack licensePack) {
    char domainName[256];
    char* ptr = strchr(licensePack.szTlsServerName, '.');
    
    if (ptr != NULL) {
        size_t length = ptr - licensePack.szTlsServerName;
        strncpy(domainName, licensePack.szTlsServerName, length);
        domainName[length] = '\0';
        return domainName;
    } else {
        return "Invalid server name";
    }
}

int main() {
    LicPack pack;
    strcpy(pack.szTlsServerName, "example.com");
    printf("Domain name: %s\n", processLicensePack(pack));
    return 0;
}
