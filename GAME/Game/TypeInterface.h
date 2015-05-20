#ifndef TypeInterface_H
#define TypeInterface_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "TypeBehaviour.h"

class TypeInterface
{
	public:
		enum ElementalType;
		TypeInterface();
		void setType(int type);
		stringw getType();
		int getMultiplyer(stringw bulletType);
	private:
		TypeBehaviour *typebehave_;
};

#endif TypeInterface_H