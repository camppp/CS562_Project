#include "VolumeEvent.h"

class VolumeEvent {
public:
    // constructor
    VolumeEvent(uint32 type, vnode_id target)
        : Referencable(true),
          fType(type),
          fTarget(target)
    {
        // Add your code here
    }

    // Member variables
    uint32 fType;
    vnode_id fTarget;

    // Member functions
    uint32 getType() {
        return fType;
    }

    vnode_id getTarget() {
        return fTarget;
    }

    void setTarget(vnode_id newTarget) {
        fTarget = newTarget;
    }
};
