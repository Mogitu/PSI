#ifndef CHARACTER_H
#define CHARACTER_H

#include "IGameObject.h"
#include "Weapon.h"

class Character : public IGameObject
{
private:
	Weapon* weapon;
public:
	int health;
	void setWeapon(Weapon* w) { weapon = w; }
	virtual void takeDamage(int amount) {};
};


#endif