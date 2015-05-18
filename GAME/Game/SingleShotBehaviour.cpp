#include "SingleShotBehaviour.h"

void SingleShotBehaviour::setUpWeaponBehaviour(GameWorld* w)
{
	this->setWorld(w);
}

void SingleShotBehaviour::doWeaponBehaviour(btVector3 &offset, btVector3 &direction, stringw name)
{
	Projectile *p = new Projectile(Common::smgr, Common::helper, name);
	p->fire(offset, direction);
	this->getWorld()->addGameObject(p);

	Common::soundEngine->play2D("../Assets/Sounds/shoot.wav");
}