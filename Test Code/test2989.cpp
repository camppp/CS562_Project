#include <iostream>
#include <string>
#include <mscoree.h>
#include <metahost.h>

#pragma comment(lib, "mscoree.lib")

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage:" << std::endl;
        std::cout << std::endl;
        std::cout << "DnaInfo.exe <assembly>" << std::endl;
        return 1;
    }

    LPCWSTR assemblyName = L"YourAssemblyName.dll"; // Replace with the actual assembly name from argv[1]

    ICLRMetaHost* pMetaHost = NULL;
    ICLRRuntimeInfo* pRuntimeInfo = NULL;
    ICLRRuntimeHost* pClrRuntimeHost = NULL;

    HRESULT hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&pMetaHost);
    if (SUCCEEDED(hr))
    {
        hr = pMetaHost->GetRuntime(L"v4.0.30319", IID_ICLRRuntimeInfo, (LPVOID*)&pRuntimeInfo);
    }

    if (SUCCEEDED(hr))
    {
        BOOL loadable;
        hr = pRuntimeInfo->IsLoadable(&loadable);
        if (loadable)
        {
            hr = pRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&pClrRuntimeHost);
        }
    }

    if (SUCCEEDED(hr))
    {
        hr = pClrRuntimeHost->Start();
    }

    if (SUCCEEDED(hr))
    {
        DWORD dwSize = 0;
        hr = pClrRuntimeHost->ExecuteInDefaultAppDomain(assemblyName, L"DnaInfo.EntryPoint", L"GetAssemblyInfo", L"YourParameter", &dwSize, NULL);
        if (SUCCEEDED(hr))
        {
            LPWSTR result = new WCHAR[dwSize];
            hr = pClrRuntimeHost->ExecuteInDefaultAppDomain(assemblyName, L"DnaInfo.EntryPoint", L"GetAssemblyInfo", L"YourParameter", &dwSize, result);
            if (SUCCEEDED(hr))
            {
                std::wcout << result << std::endl;
            }
            delete[] result;
        }
    }

    if (pClrRuntimeHost)
    {
        pClrRuntimeHost->Release();
    }
    if (pRuntimeInfo)
    {
        pRuntimeInfo->Release();
    }
    if (pMetaHost)
    {
        pMetaHost->Release();
    }

    return 0;
}
