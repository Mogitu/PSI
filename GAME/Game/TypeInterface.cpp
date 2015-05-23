#include "TypeInterface.h"
#include "FireType.h"

void TypeInterface::setType(ElementalType type)
{
	delete typebehave_;
	if (type == Fire)
	{
		typebehave_ = new FireType(ElementalType::Fire);
		typebehave_->initializer();
	}
}

int TypeInterface::getMultiplyer(ElementalType bulletType)
{
	return typebehave_->multiplyer(bulletType);
}

ElementalType TypeInterface::getType()
{
	return typebehave_->getType();
}