#include "Projectile.h"


Projectile::Projectile(ISceneManager *smgr, BulletHelper *h, stringw projectileName) :smgr(smgr), h(h), projectileName(projectileName)
{
	Initialize();	
}

Projectile::Projectile()
{
	warmedUp = false;
}

Projectile::~Projectile()
{
	
}

void Projectile::Initialize()
{	
	aliveTime = 0.0f;
	maxLifeTime = 3.0f;
	speed = 4000;
	damage = 10;
	isAlive = true;
	mesh = smgr->getGeometryCreator()->createSphereMesh(5, 16, 16);
	node = smgr->addMeshSceneNode(mesh);
	node->setName(projectileName);		
	body = h->createBody(this, Shape_Type::SPHERE,10);
	body->setLinearFactor(btVector3(1, 0, 1));	
}

void Projectile::Initialize(ISceneManager *smgr, BulletHelper *h, stringw projectileName, btVector3 &pos, btVector3 &dir, ElementalType eType, int dmg, stringw textPath)
{	
	aliveTime = 0.0f;
	maxLifeTime = 3.0f;
	elementalType = eType;
	damage = dmg;
	if (!warmedUp)
	{		
		speed = 4000;
		isAlive = true;
		mesh = smgr->getGeometryCreator()->createSphereMesh(3, 16, 16);
		node = smgr->addMeshSceneNode(mesh);
		node->setName(projectileName);
		//node->setPosition(vector3df(0, 20, 0));
		body = h->createBody(this, Shape_Type::SPHERE, 10);
		body->setLinearFactor(btVector3(1, 0, 1));
		warmedUp = true;
		node->setMaterialTexture(0, Common::device->getVideoDriver()->getTexture(textPath));
		switch (elementalType)
		{
		case Fire:
			a = ParticleManager::createFullParticleEffect("../Assets/shootEffect.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()));
			b = ParticleManager::createFullParticleEffect("../Assets/trail.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()), node);
			c = ParticleManager::createFullParticleEffect("../Assets/projectilefire.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()), node);
			break;
		case Ice:
			a = nullptr;
			b = nullptr;
			c = ParticleManager::createFullParticleEffect("../Assets/projectileIce.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()), node);
			break;
		case Wind:
			a = nullptr;
			b = nullptr;
			c = ParticleManager::createFullParticleEffect("../Assets/projectileWind.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()), node);
			c->psNode->setParticlesAreGlobal(false);
			break;
		case Earth:
			a = nullptr;
			b = nullptr;
			c = ParticleManager::createFullParticleEffect("../Assets/projectileEarth.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()), node);
			break;
		}
		
		
	}
	else
	{
		revive();
	}	
	node->setName(projectileName);
	btTransform t;
	t.setOrigin(pos);
	body->setWorldTransform(t);
	body->applyCentralImpulse(dir*speed);		
}

void Projectile::Update(u32 deltaTime)
{	
	if (isAlive)
	{
		aliveTime += deltaTime;
		if (aliveTime >= maxLifeTime * 1000)
		{
			isAlive = false;
			aliveTime = 0.0f;
		}
	}	
}

void Projectile::revive()
{
	body->setLinearVelocity(btVector3(0, 0, 0));
	//ISceneNode *Node = static_cast<ISceneNode *>(body->getUserPointer());
	node->setVisible(true);
	aliveTime = 0;		
	body->setActivationState(1);
	body->setCollisionFlags(0);
	isAlive = true;
}

void Projectile::fire(btVector3 &pos, btVector3 &dir)
{	
	a=ParticleManager::createFullParticleEffect("../Assets/shootEffect.xml", vector3df(pos.getX(),pos.getY(),pos.getZ()));
	b=ParticleManager::createFullParticleEffect("../Assets/trail.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()),node);
	c=ParticleManager::createFullParticleEffect("../Assets/projectilefire.xml", vector3df(pos.getX(), pos.getY(), pos.getZ()), node);
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
	//ISceneNode *Node = static_cast<ISceneNode *>(body->getUserPointer());

	if (a)
		a->psNode->clearParticles();
	
	if (b)
		b->psNode->clearParticles();
	
	if (c)
		c->psNode->clearParticles();

	//Node->remove();
	isAlive = false;
	node->setVisible(false);
	body->setCollisionFlags(4);
	//// Remove the object from the world
	//h->getWorld()->removeRigidBody(body);
	//// Free memory
	////delete body->getMotionState();
	//delete body->getCollisionShape();
	//delete body;
}

ElementalType Projectile::getElementalType()
{
	return elementalType;
}

int Projectile::getDamage()
{
	return damage;
}


GameObjectType Projectile::getType() const
{
	return GameObjectType::PROJECTILE;
}

