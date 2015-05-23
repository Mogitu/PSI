#ifndef FireType_H
#define FireType_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TypeBehaviour.h"

using namespace irr;
using namespace core;

class FireType : public TypeBehaviour
{
public:
	FireType(ElementalType type) : TypeBehaviour(type){};
private:
	void initialize();
};

#endif FireType_H