#include <windows.h>

#define MAX_DROPTARGETS 10

class CDropTargetWrap {
public:
    CDropTargetWrap(IDropTarget** ppdt, HWND hwnd);
    void AddDropTarget(IDropTarget* pdt);
    int GetDropTargetCount();

private:
    IDropTarget* _rgpdt[MAX_DROPTARGETS];
    HWND _hwnd;
    int _cRef;
};

CDropTargetWrap::CDropTargetWrap(IDropTarget** ppdt, HWND hwnd)
    : _hwnd(hwnd)
{
    _cRef = 1;

    for (int i = 0; i < MAX_DROPTARGETS; i++, ppdt++) {
        if (*ppdt) {
            _rgpdt[i] = *ppdt;
        }
    }
}

void CDropTargetWrap::AddDropTarget(IDropTarget* pdt) {
    for (int i = 0; i < MAX_DROPTARGETS; i++) {
        if (_rgpdt[i] == NULL) {
            _rgpdt[i] = pdt;
            return;
        }
    }
    // Handle error: Maximum number of drop targets reached
    // You can throw an exception, log an error, or handle it based on the application's requirements
}

int CDropTargetWrap::GetDropTargetCount() {
    int count = 0;
    for (int i = 0; i < MAX_DROPTARGETS; i++) {
        if (_rgpdt[i] != NULL) {
            count++;
        }
    }
    return count;
}
