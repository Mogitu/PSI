#include "WindWeapon.h"

void WindWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), getDamagePerProjectile(), "../Assets/textures/windpickup.png");
		canShoot = false;
	}
}

ElementalType WindWeapon::getWeaponElementalType()
{
	return ElementalType::Wind;
}