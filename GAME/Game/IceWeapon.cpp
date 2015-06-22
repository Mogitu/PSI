#include "IceWeapon.h"

void IceWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	fire(offset, direction, name, getDamagePerProjectile());
}

void IceWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name, int totalDamageProjectile)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), totalDamageProjectile, "../Assets/textures/firepickup.png");
		canShoot = false;
	}
}

ElementalType IceWeapon::getWeaponElementalType()
{
	return ElementalType::Ice;
}