#include "WindWeapon.h"

void WindWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	fire(offset, direction, name, getDamagePerProjectile());
}

void WindWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name, int totalDamageProjectile)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), totalDamageProjectile, "../Assets/textures/firepickup.png");
		canShoot = false;
	}
}

ElementalType WindWeapon::getWeaponElementalType()
{
	return ElementalType::Wind;
}