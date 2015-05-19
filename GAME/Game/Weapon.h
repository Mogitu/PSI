#ifndef WEAPON_H
#define WEAPON_H

#include "WeaponBehaviour.h"

class Weapon
{
private:
	WeaponBehaviour* weaponBehaviour;
	u32 shootIntervalTimer;
	u32 shootInterval;
public:
	bool canShoot;
	void Initialize(WeaponBehaviour* wpb, GameWorld* w, u32 interval)
	{ 
		weaponBehaviour = wpb;
		weaponBehaviour->setUpWeaponBehaviour(w); 
		shootIntervalTimer = 0;
		shootInterval = interval;
		canShoot = true;

	}
	WeaponBehaviour* getWeaponBehaviour() const { return weaponBehaviour; }
	void Update(irr::u32 frameDeltaTime)
	{
		if (!canShoot)
			shootIntervalTimer += frameDeltaTime;

		if (shootIntervalTimer >= shootInterval)
		{
			shootIntervalTimer = 0;
			canShoot = true;
		}

		weaponBehaviour->Update(frameDeltaTime);
	}
	virtual void fire(btVector3 &offset, btVector3 &direction, stringw name) = 0;
	~Weapon() { delete weaponBehaviour; }
};


#endif