#include <sstream>
#include <iomanip>

namespace phosphor
{
    namespace smbios
    {
        std::string System::uUID(std::string value)
        {
            uint8_t* dataIn = storage;
            dataIn = getSMBIOSTypePtr(dataIn, systemType);
            if (dataIn != nullptr)
            {
                auto systemInfo = reinterpret_cast<struct SystemInfo*>(dataIn);
                std::stringstream stream;

                // Assuming the UUID is stored as 16 bytes starting from systemInfo->uuid[0]
                for (int i = 0; i < 16; i++)
                {
                    stream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(systemInfo->uuid[i]);
                }
                return stream.str();
            }
            else
            {
                // Handle the case when the System Information type is not found
                return "UUID not found";
            }
        }
    }
}
