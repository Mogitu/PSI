#ifndef CHARACTER_H
#define CHARACTER_H

#include "IGameObject.h"
#include "WeaponFactory.h"
#include "_Level.h"

class Character : public IGameObject
{
private:
	Weapon* weapon;
	int maxHealth;
public:
	LevelProgress* level;
	LevelAttribute* attribute;
	int health;
	void setWeapon(Weapon* w) { weapon = w; }
	Weapon* getWeapon() const { return weapon; }
	void increaseMovementSpeed(int amount)
	{
		speed += amount;
	}
	void increaseMaxHealth(int amount)
	{
		maxHealth += amount;

		health = maxHealth;
	}
	void setLevelProgress(LevelProgress* level, int XP)
	{
		this->level = level;
		ExpierencePoints = XP;

		if (attribute)
			this->level->setAttribute(attribute);			
	}
	void setLevelAttribute(LevelAttribute* attribute)
	{
		this->attribute = attribute;
		this->attribute->setCharacter(this);

		if (level)
			this->level->setAttribute(attribute);
	}
	int getMaxHealth()
	{
		return maxHealth;
	}
	int getExpierncePoints() 
	{
		if (!isAlive)
			return ExpierencePoints;

		return 0;
	}
	virtual void takeDamage(int damage, ElementalType eType = ElementalType::NONE) = 0;
	~Character()
	{
		delete weapon;
	}
protected:
	int ExpierencePoints;
	float speed = 50;
};


#endif