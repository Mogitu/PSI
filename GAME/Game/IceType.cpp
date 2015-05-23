#include "IceType.h"


void IceType::initialize()
{
	addWeakness(ElementalType::Wind, 1);
	addStrengths(ElementalType::Fire, 1);
}