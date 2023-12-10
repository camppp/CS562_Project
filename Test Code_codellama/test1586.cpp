#include <windows.h>

#define MAX_DROPTARGETS 10

class CDropTargetWrap {
public:
    CDropTargetWrap(IDropTarget** ppdt, HWND hwnd) {
        _hwnd = hwnd;
        _cRef = 1;
        for (int i = 0; i < MAX_DROPTARGETS; i++) {
            _rgpdt[i] = ppdt[i];
        }
    }

    void AddDropTarget(IDropTarget* pdt) {
        if (_cRef >= MAX_DROPTARGETS) {
            // Error handling: maximum number of drop targets reached
            return;
        }
        _rgpdt[_cRef] = pdt;
        _cRef++;
    }

    int GetDropTargetCount() {
        return _cRef;
    }

private:
    IDropTarget* _rgpdt[MAX_DROPTARGETS];
    HWND _hwnd;
    int _cRef;
};
