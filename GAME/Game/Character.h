#ifndef CHARACTER_H
#define CHARACTER_H

#include "IGameObject.h"
#include "WeaponFactory.h"

class Character : public IGameObject
{
private:
	Weapon* weapon;
public:
	int health;
	void setWeapon(Weapon* w) { weapon = w; }
	Weapon* getWeapon() const { return weapon; }
	virtual void takeDamage(int damage, ElementalType eType = ElementalType::NONE) = 0;
	
	virtual ~Character()
	{
		delete weapon;
	}
};


#endif