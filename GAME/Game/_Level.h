#ifndef C_LEVEL_H
#define C_LEVEL_H

#include "LevelAttribute.h"

class LevelProgress

{
private:
	int level;
	int currentExperiencePoints;
	int baseExperiencePoints;
	LevelAttribute* attribute;
public:
	LevelProgress(int n = 1, int baseXP = 100);
	void setAttribute(LevelAttribute* attribute);
	int getLevel() const;
	int getCurrentExperiencePoints() const;
	void LevelUp(int n = 1);
	void GrantExperiencePoints(int amount);
	int ExperiencePointsNeeded();
};

#endif