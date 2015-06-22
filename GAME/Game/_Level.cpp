#include "_Level.h"
#include "LevelAttribute.h"
#include <cmath>

LevelProgress::LevelProgress(int n, int baseXP)
{
	if (n <= 0)
		n = 1;

	level = n;
	baseExperiencePoints = baseXP;
	currentExperiencePoints = 0;
}

void LevelProgress::setAttribute(LevelAttribute* attribute)
{
	this->attribute = attribute;
	attribute->increaseAttributes(level - 1, level - 1);
}

int LevelProgress::getLevel() const
{
	return level;
}

int LevelProgress::getCurrentExperiencePoints() const
{
	return currentExperiencePoints;
}

void LevelProgress::GrantExperiencePoints(int amount)
{
	currentExperiencePoints += amount;

	if (currentExperiencePoints >= ExperiencePointsNeeded())
		LevelUp();			
}

int LevelProgress::ExperiencePointsNeeded()
{
	return baseExperiencePoints * (pow(level, 2));
}

void LevelProgress::LevelUp(int n)
{
	level += n;

	if (attribute)
		attribute->increaseAttributes(n, n);
}

