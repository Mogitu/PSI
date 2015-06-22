#ifndef WEAPON_H
#define WEAPON_H

#include "WeaponBehaviour.h"
#include "Elementals.h"

class Weapon
{
private:
	WeaponBehaviour* weaponBehaviour;
	u32 shootIntervalTimer;
	u32 shootInterval;
	int damagePerProjectile;
	int totalDamagePerProjectile;
public:
	bool canShoot;
	void Initialize(WeaponBehaviour* wpb, GameWorld* w, u32 interval, int dpp) 
	{ 
		weaponBehaviour = wpb;
		weaponBehaviour->setUpWeaponBehaviour(w); 
		shootIntervalTimer = 0;
		shootInterval = interval;
		damagePerProjectile = dpp;
	}
	WeaponBehaviour* getWeaponBehaviour() const { return weaponBehaviour; }
	virtual void Update(irr::u32 frameDeltaTime)
	{
		if (!canShoot)
			shootIntervalTimer += frameDeltaTime;

		if (shootIntervalTimer >= shootInterval)
		{
			shootIntervalTimer = 0;
			canShoot = true;
		}

		if (weaponBehaviour)
			weaponBehaviour->Update(frameDeltaTime);
	}
	virtual void fire(btVector3 &offset, btVector3 &direction, stringw name) = 0;
	virtual void fire(btVector3 &offset, btVector3 &direction, stringw name, int totalDamageProjectile) = 0;
	virtual ElementalType getWeaponElementalType() = 0;
	virtual int getDamagePerProjectile() 
	{ 
		return damagePerProjectile;
	}
	void increaseWeaponDamage(int amount)
	{
		totalDamagePerProjectile += amount;
	}
	~Weapon() { delete weaponBehaviour; }	
};


#endif