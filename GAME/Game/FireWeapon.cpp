#include "FireWeapon.h"

void FireWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), getDamagePerProjectile(),"../Assets/textures/firepickup.png");
		canShoot = false;
	}
}

ElementalType FireWeapon::getWeaponElementalType()
{
	return ElementalType::Fire;
}