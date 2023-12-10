#include <vector>
#include <string>
#include <iostream>

#include "com/sun/star/util/XMacroExpander.hpp"
#include "com/sun/star/util/XOfficeInstallationDirectories.hpp"
#include "comphelper/processfactory.hxx"
#include "cppuhelper/bootstrap.hxx"

using namespace com::sun::star::uno;
using namespace com::sun::star::util;
using namespace com::sun::star::lang;

std::vector<std::string> getOpenOfficeInstallationDirectories()
{
    std::vector<std::string> installationDirectories;

    try
    {
        Reference<XComponentContext> xComponentContext = comphelper::getProcessComponentContext();
        Reference<XMultiServiceFactory> xServiceFactory = cppu::bootstrap();
        Reference<XInterface> xInterface = xServiceFactory->createInstance("com.sun.star.util.OfficeInstallationDirectories");

        Reference<XOfficeInstallationDirectories> xOfficeInstallationDirectories(xInterface, UNO_QUERY);
        if (xOfficeInstallationDirectories.is())
        {
            Sequence<OUString> directories = xOfficeInstallationDirectories->getDirectories();
            for (const auto &directory : directories)
            {
                installationDirectories.push_back(std::string(directory.getStr(), directory.getLength()));
            }
        }
    }
    catch (const Exception &e)
    {
        std::cerr << "An error occurred while retrieving OpenOffice installation directories: " << e.Message << std::endl;
    }

    return installationDirectories;
}

int main()
{
    std::vector<std::string> directories = getOpenOfficeInstallationDirectories();
    for (const auto &directory : directories)
    {
        std::cout << directory << std::endl;
    }

    return 0;
}
