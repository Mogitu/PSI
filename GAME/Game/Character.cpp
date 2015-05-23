#include "Character.h"

void Character::selectWeapon(ElementalType type, WeaponBehaviour* wpb, u32 interal, int damage, GameWorld* world)
{
	//Clean up current weapon
	delete weapon;

	switch (type)
	{
	case Fire:
		weapon = new FireWeapon();
		cout << "Fire Weapon Selected!\n";
		break;
	case Ice:
		weapon = new IceWeapon();
		cout << "Ice Weapon Selected!\n";
		break;
	case Wind:
		weapon = new WindWeapon();
		cout << "Wind Weapon Selected!\n";
		break;
	default:
		weapon = nullptr;
		cout << "Unknown weapon type provided!!\n";
		break;
	}

	if (weapon)
	{
		weapon->Initialize(wpb, world, interal, damage);
		//Prevent player from shooting more projectiles per second by constantly switching weapons
		weapon->canShoot = false;
	}
		
}