#include "irrlicht.h"
#include "TypeInterface.h"

using namespace irr;
using namespace core;


class TypeInterface
{
public:
	enum ElementalType
	{
		Fire, Ice, Wind
	};
	TypeInterface()
	{
		typebehave_ = NULL;
	}
	void setType(int type);
	stringw getType();
	int getMultiplyer(stringw bulletType);
private:
	TypeBehaviour *typebehave_;
};

void TypeInterface::setType(int type)
{
	delete typebehave_;
	if (type == Fire)
	{
		typebehave_ = new FireType("Fire");
		typebehave_->initializer;
	}
}

int TypeInterface::getMultiplyer(stringw bulletType)
{
	return typebehave_->multiplyer(bulletType);
}

stringw TypeInterface::getType()
{
	return typebehave_->getType();
}