#ifndef WEAPONBEHAVIOUR_H
#define WEAPONBEHAVIOUR_H

#include <irrlicht.h>
#include "BulletHelper.h"
#include "ParticleManager.h"
#include "Projectile.h"
#include "GameWorld.h"

class WeaponBehaviour
{
private:
	GameWorld* world;
public:
	void setWorld(GameWorld* w) { world = w; };
	GameWorld* getWorld() { return world; }
	virtual void setUpWeaponBehaviour(GameWorld* w) = 0;
	virtual void doWeaponBehaviour(btVector3 &offset, btVector3 &direction, stringw name) = 0;


};

#endif