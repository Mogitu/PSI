#ifndef WEAPON_H
#define WEAPON_H

#include "WeaponBehaviour.h"

class Weapon
{
private:
	WeaponBehaviour* weaponBehaviour;
public:
	void setWeaponBehaviour(WeaponBehaviour* wpb) { weaponBehaviour = wpb; }
	virtual void fire() = 0;
};


#endif