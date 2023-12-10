#include <Windows.h>

void initializeSecurityDescriptor(SECURITY_DESCRIPTOR *sd) {
    InitializeSecurityDescriptor(sd, SECURITY_DESCRIPTOR_REVISION);
}
