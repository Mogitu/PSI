#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "InputReceiver.h"
#include <btBulletCollisionCommon.h>
#include "BulletHelper.h"

class Player
{
private:
	InputReceiver* input;
	btRigidBody* body;
	scene::IAnimatedMeshSceneNode* node;

public:
	Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass,vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Initialize(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Update(f32 frameDeltaTime);
	void PlayerMovement(f32 frameDeltaTime);
};

#endif // !__PLAYER_H__
