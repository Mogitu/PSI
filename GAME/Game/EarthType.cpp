#include "EarthType.h"


void EarthType::initialize()
{
	addWeakness(ElementalType::Wind, 1);
	addStrengths(ElementalType::Ice, 1);
	addStrengths(ElementalType::Earth, 1);
}