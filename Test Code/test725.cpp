#include <vector>
#include <string>
#include <openoffice/ooo/ooo.h>

std::vector<std::string> getOpenOfficeInstallationDirectories()
{
    std::vector<std::string> directories;

    // Get the OpenOffice installation directories
    OOo::Installation::InstallationManager manager;
    manager.getInstallationDirectories(directories);

    // Return the installation directories
    return directories;
}
