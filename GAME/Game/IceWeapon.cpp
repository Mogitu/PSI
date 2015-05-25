#include "IceWeapon.h"

void IceWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), getDamagePerProjectile());
		canShoot = false;
	}
}

ElementalType IceWeapon::getWeaponElementalType()
{
	return ElementalType::Ice;
}