#ifndef TypeBehaviour_H
#define TypeBehaviour_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "Elementals.h"
#include "FireType.h"
#include "IceType.h"
#include "WindType.h"

using namespace irr;
using namespace core;

class TypeBehaviour
{
	public:
		TypeBehaviour(ElementalType type) : type_(type){}
		ElementalType getType();
		void addWeakness(ElementalType weakness, int value);
		void addStrengths(ElementalType strengths, int value);
		int multiplyer(ElementalType bullettype);
		void initializer();
	protected:
		ElementalType type_;

	private:
		map<ElementalType, int> weaknessElements;
		map<ElementalType, int> strengthsElements;
		virtual void initialize() = 0;
};

#endif TypeBehaviour_H