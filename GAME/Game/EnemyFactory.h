#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <irrlicht.h>
#include "Enemy.h"


class EnemyFactory
{
public:
	static Enemy* createEnemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, scene::IAnimatedMeshSceneNode *mesh, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1))
	{
		//TODO: WRONG ELEMENT TYPE! There is no weapon for none elementals... so for now lets just use fire
		return new Enemy(smgr, irrDriver, helper, world, mesh, bodyType, bodyMass, ElementalType::Fire, position, rotation, scale);
	}

	static Enemy* createFireEnemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, scene::IAnimatedMeshSceneNode *mesh, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1))
	{
		return new Enemy(smgr, irrDriver, helper, world, mesh, bodyType, bodyMass, ElementalType::Fire, position, rotation, scale);
	}

	static Enemy* createIceEnemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, scene::IAnimatedMeshSceneNode *mesh, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1))
	{
		return new Enemy(smgr, irrDriver, helper, world, mesh, bodyType, bodyMass, ElementalType::Ice, position, rotation, scale);
	}

	static Enemy* createWindEnemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, scene::IAnimatedMeshSceneNode *mesh, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1))
	{
		return new Enemy(smgr, irrDriver, helper, world, mesh, bodyType, bodyMass, ElementalType::Wind, position, rotation, scale);
	}

	static Enemy* createEarthEnemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, scene::IAnimatedMeshSceneNode *mesh, Shape_Type bodyType, btScalar bodyMass = 1, vector3df position = vector3df(0, 0, 0), vector3df rotation = vector3df(0, 0, 0), vector3df scale = vector3df(1, 1, 1))
	{
		return new Enemy(smgr, irrDriver, helper, world, mesh, bodyType, bodyMass, ElementalType::Earth, position, rotation, scale);
	}
};

#endif