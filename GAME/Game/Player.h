#ifndef __PLAYER_H__
#define __PLAYER_H__


#include "InputReceiver.h"
#include <btBulletCollisionCommon.h>
#include "BulletHelper.h"
#include "IGameObject.h"
#include "BulletHelper.h"
#include "GameWorld.h"
#include "Projectile.h"

class Player : public IGameObject
{
private:
	InputReceiver* input;
	scene::IAnimatedMeshSceneNode* node;
	BulletHelper* helper;
	ISceneManager* smgr;
	vector2di centerScreenPosition;
	GameWorld *world;

	bool justJumped;
	bool isGrounded();
public:
	Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world,InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass = 1,vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Initialize();
	void Initialize(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Update(u32 frameDeltaTime);
	void PlayerMovement(u32 frameDeltaTime);
	void Fire();
	virtual void kill();
	const vector3df& getNodePosition() const;
	const vector3df& getNodeAbsolutePosition() const;
	scene::IAnimatedMeshSceneNode* getNode();
	GameObjectType getType();
    u32 shootInterval;
	u32 shootIntervalTimer;

	scene::IAnimatedMeshSceneNode*& n = node;
};

#endif // !__PLAYER_H__
