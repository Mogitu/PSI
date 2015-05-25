#include "WindType.h"


void WindType::initialize()
{
	addWeakness(ElementalType::Fire, 1);
	addStrengths(ElementalType::Earth, 1);
	addStrengths(ElementalType::Wind, 1);
}