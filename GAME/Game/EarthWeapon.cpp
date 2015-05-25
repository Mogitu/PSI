#include "EarthWeapon.h"


void EarthWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), getDamagePerProjectile());
		canShoot = false;
	}
}

ElementalType EarthWeapon::getWeaponElementalType()
{
	return ElementalType::Earth;
}