#include "CQCSrvDrvTI_TIServerBase.h"
#include "CQCSrvDrvTI_TIImpl.h"

class CQCSrvDrvTI_TIServerBase {
private:
    // Lazy evaluation method for exporting the facility object
    static CQCSrvDrvTI_TIImpl* getFacilityObject() {
        static CQCSrvDrvTI_TIImpl* s_pFacilityObject = nullptr;
        if (s_pFacilityObject == nullptr) {
            s_pFacilityObject = new CQCSrvDrvTI_TIImpl();
        }
        return s_pFacilityObject;
    }

public:
    // Export the facility object
    static CQCSrvDrvTI_TIImpl* getFacilityObject() {
        return getFacilityObject();
    }
};
