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
	maxLifeTime = 3;
	speed = 3000;
	isAlive = true;
	mesh = smgr->getGeometryCreator()->createSphereMesh(5, 16, 16);
	node = smgr->addMeshSceneNode(mesh);
	node->setName("Projectile");	
	//node->setPosition(vector3df(0, 20, 0));
	body = h->createBody(node, Shape_Type::SPHERE,10);
	body->setLinearFactor(btVector3(1, 0, 1));

	
}

void Projectile::Update(u32 deltaTime)
{	
	aliveTime += deltaTime;
	if (aliveTime >= maxLifeTime*1000)
	{
		isAlive = false;
	}
}



void Projectile::fire(btVector3 &pos, btVector3 &dir)
{	
	ParticleManager::createFullParticleEffect("../Assets/shootEffect.xml", vector3df(pos.getX(),pos.getY(),pos.getZ()));
	isAlive = true;
	btTransform t;	
	t.setOrigin(pos);
	body->setWorldTransform(t);
	body->applyCentralImpulse(dir*speed);
}

void Projectile::kill()
{

	//particleEffect->psNode->drop();
	//delete particleEffect;
	//particleEffect = 0;

	ISceneNode *Node = static_cast<ISceneNode *>(body->getUserPointer());
	Node->remove();
	isAlive = false;
	// Remove the object from the world
	h->getWorld()->removeRigidBody(body);
	// Free memory
	delete body->getMotionState();
	delete body->getCollisionShape();
	delete body;
}

void Projectile::resurrect()
{
	isAlive = true;
	body->setActivationState(1);
	body->setCollisionFlags(0);
}

GameObjectType Projectile::getType() const
{
	return GameObjectType::PROJECTILE;
}

