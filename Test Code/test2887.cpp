#include <Windows.h>

class CFileSecurity
{
private:
    LPWSTR m_filename;
    PSECURITY_DESCRIPTOR m_securityDescriptor;

public:
    CFileSecurity(LPWSTR filename) : m_filename(filename), m_securityDescriptor(nullptr)
    {
        // Retrieve the current security descriptor of the file
        DWORD dwRes;
        PSECURITY_DESCRIPTOR pSD = nullptr;
        if (GetNamedSecurityInfo(m_filename, SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, nullptr, nullptr, nullptr, nullptr, &pSD) == ERROR_SUCCESS)
        {
            m_securityDescriptor = pSD;
        }
        else
        {
            // Handle error
            // ...
        }
    }

    ~CFileSecurity()
    {
        if (m_securityDescriptor != nullptr)
        {
            LocalFree(m_securityDescriptor);
            m_securityDescriptor = nullptr;
        }
    }

    // Apply a new DACL to the file's security descriptor
    void ApplyDACL(PACL pDacl)
    {
        if (m_securityDescriptor != nullptr)
        {
            if (SetSecurityDescriptorDacl(m_securityDescriptor, TRUE, pDacl, FALSE))
            {
                // DACL applied successfully
            }
            else
            {
                // Handle error
                // ...
            }
        }
        else
        {
            // Handle error - security descriptor not initialized
            // ...
        }
    }

    // Save the modified security descriptor back to the file
    void SaveSecurityDescriptor()
    {
        if (m_securityDescriptor != nullptr)
        {
            if (SetNamedSecurityInfo(m_filename, SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, nullptr, nullptr, m_securityDescriptor, nullptr) != ERROR_SUCCESS)
            {
                // Handle error
                // ...
            }
        }
        else
        {
            // Handle error - security descriptor not initialized
            // ...
        }
    }
};
