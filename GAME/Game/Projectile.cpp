#include "Projectile.h"


Projectile::Projectile(ISceneManager *smgr, BulletHelper *h) :smgr(smgr), h(h)
{
	init();
}


void Projectile::init()
{
	mesh = smgr->getGeometryCreator()->createSphereMesh(5,16,16);
	node = smgr->addMeshSceneNode(mesh);
	node->setPosition(vector3df(0,20,0));
	body = h->createBody(node, Shape_Type::SPHERE, 10);	
}

void Projectile::fire(btVector3 &pos, btVector3 &dir)
{	
	alive = true;
	btTransform t;	
	t.setOrigin(pos);
	body->setWorldTransform(t);
	body->applyCentralImpulse(dir*10);
}


void Projectile::update(u32 deltaTime)
{
	if (!alive)
	{
		return;
	}
	aliveTime += deltaTime;		
}

void Projectile::kill()
{
	alive = false;
	body->setActivationState(0);
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
}

void Projectile::resurrect()
{
	alive = true;
	body->setActivationState(1);
	body->setCollisionFlags(0);
}

