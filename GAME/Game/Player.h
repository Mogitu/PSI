#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "InputReceiver.h"
#include "BulletHelper.h"
#include "IGameObject.h"
#include "GameWorld.h"


class Player : public IGameObject
{
private:
	InputReceiver* input;
	//scene::IAnimatedMeshSceneNode* node;
	BulletHelper* helper;
	ISceneManager* smgr;
	vector2di centerScreenPosition;
	GameWorld *world;	
	bool justJumped;
	bool isGrounded();
	int score;
	float restriction = 1; //1 = no restriction; 0 = stop movement
	float speed = 50;
public:
	Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world,InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass = 1,vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Initialize();
	void Initialize(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Update(u32 frameDeltaTime);
	void PlayerMovement(u32 frameDeltaTime);
	void Fire();
	virtual void kill();
	virtual void revive();
	virtual void takeDamage(int amount);
	const vector3df& getNodePosition() const;
	const vector3df& getNodeAbsolutePosition() const;
	scene::IAnimatedMeshSceneNode* getNode();
	GameObjectType getType() const;
    u32 shootInterval;
	u32 shootIntervalTimer;	
	void increaseScore(int amount);
	int getScore();
	//scene::IAnimatedMeshSceneNode*& n = (IAnimatedMeshSceneNode*)node;
};

#endif // !__PLAYER_H__
