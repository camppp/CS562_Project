#include <objbase.h>

class CDurationTool
{
public:
    STDMETHODIMP GetClassID(CLSID* pClassID)
    {
        if (pClassID)
        {
            *pClassID = CLSID_DirectMusicDurationTool;
            return S_OK;
        }
        return E_POINTER;
    }
};
