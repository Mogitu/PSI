#ifndef Game_World_H
#define Game_World_H

#include <irrlicht.h>
#include "IGameObject.h"
#include "BulletHelper.h"

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
public:
	GameWorld(BulletHelper *h, IrrlichtDevice *device);
	~GameWorld();
	void clearGameObjects();
	void update(u32 frameDeltaTime);
	void updatePhysics(btRigidBody *body);
	void addGameObject(IGameObject* gameObject);
	void removeGameObject(IGameObject* gameObject);
};

#endif // !Game_World_H
