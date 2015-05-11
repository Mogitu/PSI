#ifndef FIREWEAPON_H
#define FIREWEAPON_H

#include "Weapon.h"

class FireWeapon : Weapon
{
public:
	void fire() override;
};

#endif