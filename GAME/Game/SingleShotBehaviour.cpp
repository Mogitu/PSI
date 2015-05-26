#include "SingleShotBehaviour.h"

void SingleShotBehaviour::setUpWeaponBehaviour(GameWorld* w)
{
	this->setWorld(w);
}

void SingleShotBehaviour::doWeaponBehaviour(btVector3 &offset, btVector3 &direction, stringw name, ElementalType eType, int damagePerProjectile, stringw path)
{
	Projectile *p = getPool()->create();
	if (p)
	{
		if (!p->warmedUp)
		{
			this->getWorld()->addGameObject(p);
		}

		p->Initialize(Common::smgr, Common::helper, name, offset, direction, eType, damagePerProjectile, path);
		Common::soundEngine->play2D("../Assets/Sounds/shoot.wav");
	}
}