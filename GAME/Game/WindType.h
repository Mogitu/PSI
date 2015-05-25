#ifndef WindType_H
#define WindType_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TypeBehaviour.h"

using namespace irr;
using namespace core;

class WindType : public TypeBehaviour
{
public:
	WindType(ElementalType type) : TypeBehaviour(type){};
private:
	void initialize();
};

#endif WindType_H