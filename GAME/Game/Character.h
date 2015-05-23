#ifndef CHARACTER_H
#define CHARACTER_H

#include "IGameObject.h"
#include "Weapon.h"
#include "FireWeapon.h"
#include "IceWeapon.h"
#include "WindWeapon.h"
#include "SingleShotBehaviour.h"

class Character : public IGameObject
{
private:
	Weapon* weapon;
public:
	int health;
	void setWeapon(Weapon* w) { weapon = w; }
	Weapon* getWeapon() const { return weapon; }
	virtual void takeDamage(int amount) {};
	void selectWeapon(ElementalType type, WeaponBehaviour* wpb, u32 interal, int damage, GameWorld* world);
	~Character()
	{
		delete weapon;
	}
};


#endif