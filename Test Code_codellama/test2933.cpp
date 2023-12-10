#include <SupportDefs.h>

class VolumeEvent : public Referencable {
public:
	VolumeEvent(uint32 type, vnode_id target);
	
	uint32 getType();
	vnode_id getTarget();
	void setTarget(vnode_id newTarget);
	
private:
	uint32 fType;
	vnode_id fTarget;
};

VolumeEvent::VolumeEvent(uint32 type, vnode_id target)
	: Referencable(true),
	  fType(type),
	  fTarget(target)
{
}

uint32 VolumeEvent::getType()
{
	return fType;
}

vnode_id VolumeEvent::getTarget()
{
	return fTarget;
}

void VolumeEvent::setTarget(vnode_id newTarget)
{
	fTarget = newTarget;
}
