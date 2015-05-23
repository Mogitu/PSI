#include "TypeInterface.h"


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

int TypeInterface::getMultiplyer(ElementalType bulletType)
{
	return typebehave_->multiplyer(bulletType);
}

ElementalType TypeInterface::getType()
{
	return typebehave_->getType();
}