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
	static ObjectPool<Projectile> *pool[4];
public:
	void setWorld(GameWorld* w) { world = w; };
	static void createFourPools()
	{
		//TODO: Static.. alot of fun offcourse:)
			for (int n = 0; n < 4; n++)
				pool[n] = new ObjectPool<Projectile>(40);
	}
	GameWorld* getWorld() { return world; }
	ObjectPool<Projectile>* getPool(int n) const { return pool[n]; }
	virtual void setUpWeaponBehaviour(GameWorld* w) = 0;
	virtual void doWeaponBehaviour(btVector3 &offset, btVector3 &direction, stringw name, ElementalType eType, int damagePerProjectile, stringw path) = 0;

	void Update(irr::u32 frameDeltaTime)
	{
		for (int n = 0; n < 4; n++)
		{
			for (int i = 0; i < pool[n]->getSize(); i++)
			{
				if (!pool[n]->getObjects()[i].data.isAlive)
				{
					pool[n]->returnToPool(&pool[n]->getObjects()[i]);
				}
			}
		}
	}

	int ElementToN(ElementalType eType)
	{
		switch (eType)
		{
		case Fire:
			return 0;
			break;
		case Ice:
			return 1;
			break;
		case Wind:
			return 2;
			break;
		case Earth:
			return 3;
			break;
		case NONE:
			return 0;
			break;
		default:
			return 0;
			break;
		}
	}

	virtual ~WeaponBehaviour()
	{
		//delete pool;
	}
};

ObjectPool<Projectile>* WeaponBehaviour::pool[4];

#endif