#include "CQCSrvDrvTI_TIServerBase.hpp"
#include "CQCSrvDrvTI_TIImpl.hpp"
#include "CQCSrvDrvTI_ThisFacility.hpp"
#include <mutex> // for std::mutex

class CQCSrvDrvTI_TIServerBase {
private:
    mutable std::mutex facilityMutex; // Mutex for thread-safe lazy initialization
    mutable std::unique_ptr<CQCSrvDrvTI_TIImpl> facilityObject; // Lazily initialized facility object

public:
    // Lazy evaluation method for exporting the facility object
    const CQCSrvDrvTI_TIImpl& GetFacilityObject() const {
        std::lock_guard<std::mutex> lock(facilityMutex); // Lock the mutex for thread safety
        if (!facilityObject) {
            facilityObject.reset(new CQCSrvDrvTI_TIImpl()); // Create the facility object if not already initialized
        }
        return *facilityObject; // Return the facility object
    }
};
