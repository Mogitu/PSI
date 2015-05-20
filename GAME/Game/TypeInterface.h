#ifndef TypeInterface_H
#define TypeInterface_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TypeBehaviour.h"

using namespace irr;
using namespace core;

class TypeInterface
{
public:
	
	TypeInterface()
	{
		typebehave_ = NULL;
	}
	void setType(ElementalType type);
	ElementalType getType();
	int getMultiplyer(ElementalType bulletType);
private:
	TypeBehaviour *typebehave_;
};

#endif TypeInterface_H