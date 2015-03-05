#ifndef __PLAYER_H__
#define __PLAYER_H__


#include "InputReceiver.h"
#include <btBulletCollisionCommon.h>
#include "BulletHelper.h"
#include "IGameObject.h"

class Player : public IGameObject
{
private:
	InputReceiver* input;
	btRigidBody* body;
	scene::IAnimatedMeshSceneNode* node;


public:
	Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass,vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Initialize();
	void Initialize(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Update(u32 frameDeltaTime);
	void PlayerMovement(u32 frameDeltaTime);
	GameObjectType getType();
};

#endif // !__PLAYER_H__
