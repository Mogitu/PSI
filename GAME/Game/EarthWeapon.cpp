#include "EarthWeapon.h"


void EarthWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), getDamagePerProjectile(), "../Assets/textures/earthpickup.png");
		canShoot = false;
	}
}

ElementalType EarthWeapon::getWeaponElementalType()
{
	return ElementalType::Earth;
}