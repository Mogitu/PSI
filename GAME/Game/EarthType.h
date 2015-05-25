#ifndef EarthType_H
#define EarthType_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TypeBehaviour.h"

using namespace irr;
using namespace core;

class EarthType : public TypeBehaviour
{
public:
	EarthType(ElementalType type) : TypeBehaviour(type){};
private:
	void initialize();
};

#endif EarthType_H