#include "TypeInterface.h"
#include "FireType.h"
#include "IceType.h"
#include "WindType.h"

void TypeInterface::setType(ElementalType type)
{
	delete typebehave_;
	if (type == Fire)
	{
		typebehave_ = new FireType(ElementalType::Fire);
		typebehave_->initializer();
	}
	else if (type == Ice)
	{
		typebehave_ = new IceType(ElementalType::Ice);
		typebehave_->initializer();
	}
	else if (type == Wind)
	{
		typebehave_ = new WindType(ElementalType::Wind);
		typebehave_->initializer();
	}
	
}

int TypeInterface::getMultiplier(ElementalType bulletType)
{
	return typebehave_->multiplier(bulletType);
}

ElementalType TypeInterface::getType()
{
	return typebehave_->getType();
}