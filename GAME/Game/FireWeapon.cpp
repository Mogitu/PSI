#include "FireWeapon.h"
#include "SingleShotBehaviour.h"

FireWeapon::FireWeapon()
{

}

void FireWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name, getWeaponElementalType(), getDamagePerProjectile());
		canShoot = false;
	}
}

ElementalType FireWeapon::getWeaponElementalType()
{
	return ElementalType::Fire;
}