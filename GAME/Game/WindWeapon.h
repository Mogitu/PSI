#ifndef WINDWEAPON_H
#define WINDWEAPON_H

#include "Weapon.h"

class WindWeapon : public Weapon
{
public:
	void fire(btVector3 &offset, btVector3 &direction, stringw name) override;
	ElementalType getWeaponElementalType() override;
};

#endif