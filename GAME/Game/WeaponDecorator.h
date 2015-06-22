#ifndef WEAPONDECORATOR_H
#define WEAPONDECORATOR_H

#include "Weapon.h"

class WeaponDecorator : public Weapon
{
protected:
	Weapon* prevWeapon;
public:
	void fire(btVector3 &offset, btVector3 &direction, stringw name, int totalProjectileDamage) override
	{
		if (prevWeapon)
			prevWeapon->fire(offset, direction, name, totalProjectileDamage + prevWeapon->getDamagePerProjectile());
	}

	void fire(btVector3 &offset, btVector3 &direction, stringw name) override
	{
		/*if (prevWeapon)
			prevWeapon->fire(offset, direction, name, 0);*/

		fire(offset, direction, name, getDamagePerProjectile());
	}

	void Update(irr::u32 frameDeltaTime) override
	{
		if (prevWeapon)
			prevWeapon->Update(frameDeltaTime);
	}

	virtual ElementalType getWeaponElementalType() override
	{
		return prevWeapon->getWeaponElementalType();
	}

	virtual int getDamagePerProjectile() { return 0; }
};

#endif