#ifndef LEVELATTRIBUTE_H
#define LEVELATTRIBUTE_H

class Character;

class LevelAttribute
{
private:
	int constitution;
	int dexterity;

	Character* character;
	void updateCharacterStat(int constiAmount = 0, int dexAmount = 0);
public:
	LevelAttribute(int consti = 1, int dex = 1);
	void increaseAttributes(int constiAmount = 0, int dexAmount = 0);
	int getConstitution() const;
	int getDexterity() const;
	void setCharacter(Character* c);
};

#endif