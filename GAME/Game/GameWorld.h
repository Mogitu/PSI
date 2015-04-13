#ifndef Game_World_H
#define Game_World_H

#include <irrlicht.h>
#include "IGameObject.h"
#include "BulletHelper.h"
#include "ParticleManager.h"
#include "Projectile.h"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

using namespace irr;

class GameWorld
{
private:
	core::list<IGameObject*> gameObjects;
	BulletHelper *helper;
	IrrlichtDevice *device;
	IGameObject *player;
public:
	GameWorld(BulletHelper *h, IrrlichtDevice *device);
	~GameWorld();
	void clearGameObjects();
	void update(u32 frameDeltaTime);
	//void updatePhysics(btRigidBody *body);
	void addGameObject(IGameObject* gameObject);
	void removeGameObject(IGameObject* gameObject);
	void setPlayer(IGameObject *p);
	IGameObject *getPlayer();
	
};

#endif // !Game_World_H
