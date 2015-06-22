#include "LevelAttribute.h"
#include "Character.h"

LevelAttribute::LevelAttribute(int consti, int dex)
{
	constitution = consti;
	dexterity = dex;
}

void LevelAttribute::increaseAttributes(int constiAmount, int dexAmount)
{
	constitution += constiAmount;
	dexterity += dexAmount;

	updateCharacterStat(constiAmount, dexAmount);
}

int LevelAttribute::getConstitution() const
{
	return constitution;
}

int LevelAttribute::getDexterity() const
{
	return dexterity;
}

void LevelAttribute::setCharacter(Character* c)
{
	this->character = c;
	updateCharacterStat(constitution, dexterity);
}

void LevelAttribute::updateCharacterStat(int constiAmount, int dexAmount)
{
	if (character)
	{
		character->increaseMaxHealth(constiAmount * 5);
		character->increaseMovementSpeed(dexAmount * 2);
	}
}