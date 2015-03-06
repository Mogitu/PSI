#include "Projectile.h"


Projectile::Projectile(ISceneManager *smgr, BulletHelper *h) :smgr(smgr), h(h)
{
	init();	
}

Projectile::~Projectile()
{

}


void Projectile::init()
{
	aliveTime = 0;
	alive = true;
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
	body->applyCentralImpulse(dir*4000);
}


void Projectile::update(u32 deltaTime)
{
	if (!alive)
	{
		return;
	}
	aliveTime += deltaTime;
	if (aliveTime >=5000)
	{
		kill();
	}
}

void Projectile::kill()
{
	h->deactivateObject(body);
}

void Projectile::resurrect()
{
	alive = true;
	body->setActivationState(1);
	body->setCollisionFlags(0);
}

