#include "IceType.h"


void IceType::initialize()
{
	addWeakness(ElementalType::Earth, 1);
	addStrengths(ElementalType::Fire, 1);
	addStrengths(ElementalType::Ice, 1);
}