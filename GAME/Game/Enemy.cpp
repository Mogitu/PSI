#include "irrlicht.h"
#include "Enemy.h"

using namespace irr;
using namespace scene;
using namespace core;
using namespace video;

Enemy::Enemy(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *irrDriver, irr::io::path meshpath, irr::io::path texturepath, float x, float y, float z, float scalex, float scaley, float scalez) : smgr(smgr), irrDriver(irrDriver), node(), mesh()
{
	mesh = smgr->getMesh(meshpath);

	//default node setup
	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setScale(vector3df(scalex,scaley,scalez));
	node->setMaterialTexture(0, irrDriver->getTexture(texturepath));
	node->setPosition(vector3df(x, y, z));
}

void Enemy::Kill(float beginanim, float endanim, float animationspeed)
{
	node->setFrameLoop(beginanim, endanim);
	node->setAnimationSpeed(animationspeed);

	if (node->getFrameNr() == node->getEndFrame()) 
	{
		node->remove();
		node->drop();
	}
	
}