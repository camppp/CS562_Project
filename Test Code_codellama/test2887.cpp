#include <windows.h>
#include <aclapi.h>
#include <string>

class CFileSecurity
{
public:
    CFileSecurity(LPWSTR filename)
    {
        // Initialize the security descriptor
        InitializeSecurityDescriptor(&m_sd, SECURITY_DESCRIPTOR_REVISION);

        // Get the current security descriptor of the file
        GetFileSecurity(filename, OWNER_SECURITY_INFORMATION | GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION, &m_sd);
    }

    ~CFileSecurity()
    {
        // Free the security descriptor
        FreeSecurityDescriptor(&m_sd);
    }

    // Retrieve the current security descriptor of the file
    void GetSecurityDescriptor(SECURITY_DESCRIPTOR* sd)
    {
        *sd = m_sd;
    }

    // Apply a new DACL to the file's security descriptor
    void SetDacl(PACL newDacl)
    {
        // Get the current DACL
        PACL oldDacl = NULL;
        GetSecurityDescriptorDacl(&m_sd, &oldDacl, NULL);

        // Add the new DACL to the security descriptor
        AddAccessAllowedAce(m_sd, ACL_REVISION, 0, newDacl);

        // Set the new DACL on the security descriptor
        SetSecurityDescriptorDacl(&m_sd, TRUE, newDacl, FALSE);
    }

    // Save the modified security descriptor back to the file
    void SaveSecurityDescriptor()
    {
        // Get the current file name
        std::wstring filename = GetFileName();

        // Set the new security descriptor on the file
        SetFileSecurity(filename, OWNER_SECURITY_INFORMATION | GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION, &m_sd);
    }

private:
    SECURITY_DESCRIPTOR m_sd;
};
