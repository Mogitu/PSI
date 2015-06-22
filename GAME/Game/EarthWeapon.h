#ifndef EARTHWEAPON_H
#define EARTHWEAPON_H

#include "Weapon.h"

class EarthWeapon : public Weapon
{
public:
	void fire(btVector3 &offset, btVector3 &direction, stringw name) override;
	void fire(btVector3 &offset, btVector3 &direction, stringw name, int totalDamageProjectile) override;
	ElementalType getWeaponElementalType() override;
};

#endif