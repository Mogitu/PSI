#ifndef ICEWEAPON_H
#define ICEWEAPON_H

#include "Weapon.h"

class IceWeapon : public Weapon
{
public:
	void fire(btVector3 &offset, btVector3 &direction, stringw name) override;
	ElementalType getWeaponElementalType() override;
};
#endif