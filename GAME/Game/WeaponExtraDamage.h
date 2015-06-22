#ifndef WEAPONEXTRADAMAGE_H
#define WEAPONEXTRADAMAGE_H

#include "WeaponDecorator.h"

class WeaponExtraDamage : public WeaponDecorator
{
private:
	int extraDamage;
public:
	WeaponExtraDamage(int damage, Weapon* w) : extraDamage(damage) { prevWeapon = w; }

	int getDamagePerProjectile() override
	{
		return extraDamage;
	}
};

#endif