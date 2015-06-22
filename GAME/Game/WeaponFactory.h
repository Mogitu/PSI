#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H

#include "Weapon.h"
#include "FireWeapon.h"
#include "IceWeapon.h"
#include "WindWeapon.h"
#include "EarthWeapon.h"
#include "WeaponBehaviour.h"
#include "SingleShotBehaviour.h"
#include "WeaponExtraDamage.h"
#include "Elementals.h"

class WeaponFactory
{
public:
	static Weapon* createWeaponBasedOnElement(ElementalType eType, WeaponBehaviour* wpb, u32 interval, int damage, GameWorld* world)
	{
		switch (eType)
		{
		case Fire:
			return createFireWeapon(wpb, interval, damage, world);
		case Ice:
			return createIceWeapon(wpb, interval, damage, world);
		case Wind:
			return createWindWeapon(wpb, interval, damage, world);
		case Earth:
			return createEarthWeapon(wpb, interval, damage, world);
		case NONE:
			return nullptr;
		default:
			return nullptr;
			break;
		}
	}
	static Weapon* createFireWeapon(WeaponBehaviour* wpb, u32 interval, int damage, GameWorld* world)
	{
		Weapon* w = new FireWeapon();
		w->Initialize(wpb, world, interval, damage);

		return w;
	}
	static Weapon* createIceWeapon(WeaponBehaviour* wpb, u32 interval, int damage, GameWorld* world)
	{

		Weapon* w = new IceWeapon();
		w->Initialize(wpb, world, interval, damage);

		return w;
	}
	static Weapon* createWindWeapon(WeaponBehaviour* wpb, u32 interval, int damage, GameWorld* world)
	{
		Weapon* w = new WindWeapon();
		w->Initialize(wpb, world, interval, damage);

		return w;
	}

	static Weapon* createEarthWeapon(WeaponBehaviour* wpb, u32 interval, int damage, GameWorld* world)
	{
		Weapon* w = new EarthWeapon();
		w->Initialize(wpb, world, interval, damage);

		return w;
	}
};


#endif