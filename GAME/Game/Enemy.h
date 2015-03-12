#ifndef ENEMY_H
#define ENEMY_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "BulletHelper.h"
#include "GameWorld.h"
#include "IGameObject.h"

class Enemy : public IGameObject
{
public:
	Enemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, io::path meshpath, io::path texturepath, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Initialize();
	void Initialize(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, io::path meshpath, io::path texturepath, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1));
	void Update(u32 frameDeltaTime);
	void SetDeath(float begindeath = 0, float enddeath = 0, float deathspeed = 25);
	void getcurrentframe();
	virtual void kill();
private:
	irr::scene::ISceneManager *smgr;
	irr::video::IVideoDriver *irrDriver;
	irr::scene::IAnimatedMeshSceneNode* node;
	BulletHelper* helper;
	GameWorld *world;
	float begindeath;
	float enddeath;
	float deathspeed;
	float frameget;
};

#endif ENEMY_H