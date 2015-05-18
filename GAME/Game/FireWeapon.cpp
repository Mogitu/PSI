#include "FireWeapon.h"
#include "SingleShotBehaviour.h"

FireWeapon::FireWeapon()
{

}

void FireWeapon::fire(btVector3 &offset, btVector3 &direction, stringw name)
{
	//FIRE!!!!! BURN!!! AHAHAHAHA!!
	if (canShoot)
	{
		getWeaponBehaviour()->doWeaponBehaviour(offset, direction, name);
		canShoot = false;
	}
	
}