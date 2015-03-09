#include "Projectile.h"


Projectile::Projectile(ISceneManager *smgr, BulletHelper *h) :smgr(smgr), h(h)
{
	Initialize();	
}

Projectile::~Projectile()
{

}

void Projectile::Initialize()
{
	aliveTime = 0;
	maxLifeTime = 5;
	speed = 3000;
	isAlive = true;
	mesh = smgr->getGeometryCreator()->createSphereMesh(5, 16, 16);
	node = smgr->addMeshSceneNode(mesh);
	node->setPosition(vector3df(0, 20, 0));
	body = h->createBody(node, Shape_Type::SPHERE, 10);
}

void Projectile::Update(u32 deltaTime)
{
	if (!isAlive)
	{
		return;
	}
	aliveTime += deltaTime;
	if (aliveTime >= maxLifeTime*1000)
	{
		kill();
	}
}



void Projectile::fire(btVector3 &pos, btVector3 &dir)
{	
	isAlive = true;
	btTransform t;	
	t.setOrigin(pos);
	body->setWorldTransform(t);
	body->applyCentralImpulse(dir*speed);
}

void Projectile::kill()
{
	h->deactivateObject(body);
}

void Projectile::resurrect()
{
	isAlive = true;
	body->setActivationState(1);
	body->setCollisionFlags(0);
}

