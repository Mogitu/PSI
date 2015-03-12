#ifndef ENEMY_H
#define ENEMY_H

#include <irrlicht.h>
#include <iostream>
#include <string>
#include "BulletHelper.h"

class Enemy
{
public:
	Enemy(irr::scene::ISceneManager *smgr,irr::video::IVideoDriver *irrDriver, irr::io::path meshpath, irr::io::path texturepath , float x, float y, float z, float scalex, float scaley, float scalez);
	~Enemy();
	void Kill(float beginanim, float endanim, float animationspeed);
private:
	irr::scene::ISceneManager *smgr;
	irr::video::IVideoDriver *irrDriver;
	irr::scene::IAnimatedMesh* mesh;
	irr::scene::IAnimatedMeshSceneNode* node;
};

#endif ENEMY_H