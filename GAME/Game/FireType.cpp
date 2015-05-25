#include "FireType.h"

void FireType::initialize()
{
	addWeakness(ElementalType::Ice,1);
	addStrengths(ElementalType::Wind, 1);
	addStrengths(ElementalType::Fire, 1);
}