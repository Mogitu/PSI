#ifndef WEAPONPICKUP_H
#define WEAPONPICKUP_H

#include "IGameObject.h"
#include "BulletHelper.h"
#include <irrlicht.h>
#include "GameWorld.h"

class WeaponPickup : public IGameObject
{
public:
	WeaponPickup(irr::core::stringw name,BulletHelper *h, irr::scene::ISceneNode *mesh);
	virtual void Update(u32 frameDeltaTime);
	virtual void Initialize();
	virtual void kill();
	virtual void revive();
	~WeaponPickup();
private:

};


#endif 