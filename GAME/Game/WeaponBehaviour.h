#ifndef WEAPONBEHAVIOUR_H
#define WEAPONBEHAVIOUR_H

#include <irrlicht.h>
#include "BulletHelper.h"
#include "ParticleManager.h"
#include "Projectile.h"
#include "GameWorld.h"
#include "ObjectPool.h"

class WeaponBehaviour
{
private:
	GameWorld* world;
	ObjectPool<Projectile> *pool;
public:
	void setWorld(GameWorld* w) { world = w; pool = new ObjectPool<Projectile>(10); };
	GameWorld* getWorld() { return world; }
	ObjectPool<Projectile>* getPool() const { return pool; }
	virtual void setUpWeaponBehaviour(GameWorld* w) = 0;
	virtual void doWeaponBehaviour(btVector3 &offset, btVector3 &direction, stringw name, ElementalType eType, int damagePerProjectile, stringw path) = 0;

	void Update(irr::u32 frameDeltaTime)
	{
		for (int i = 0; i < pool->getSize(); i++)
		{
			if (!pool->getObjects()[i].data.isAlive)
			{
				pool->returnToPool(&pool->getObjects()[i]);
			}
		}
	}

	virtual ~WeaponBehaviour()
	{
		delete pool;
	}
};

#endif