#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

Component::Component()
{}

Component::~Component()
{}

/* Returns whether the component is deleted or not */
bool Component::IsDeleted() const {
	return mDeleted;
}
