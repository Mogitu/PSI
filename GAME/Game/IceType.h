#ifndef IceType_H
#define IceType_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TypeBehaviour.h"

using namespace irr;
using namespace core;

class IceType : public TypeBehaviour
{
public:
	IceType(ElementalType type) : TypeBehaviour(type){};
private:
	void initialize();
};

#endif IceType_H