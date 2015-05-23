#include "WindType.h"


void WindType::initialize()
{
	addWeakness(ElementalType::Fire, 1);
	addStrengths(ElementalType::Ice, 1);
}