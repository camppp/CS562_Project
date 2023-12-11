c
#include <security.h>

void initializeSecurityDescriptor(SECURITY_DESCRIPTOR* pSecurityDescriptor)
{
    InitializeSecurityDescriptor(pSecurityDescriptor, SECURITY_DESCRIPTOR_REVISION);
}
