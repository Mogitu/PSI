#include "WeaponPickup.h"


WeaponPickup::WeaponPickup(irr::core::stringw name,BulletHelper *h, irr::scene::ISceneNode *m)
{
	node = m;
	node->setName(name);
	body = h->createBody(this,Shape_Type::BOX,0);
	isAlive = true;
	stringw path = "../Assets/";
	effect = ParticleManager::createFullParticleEffect(path.append(name).append(".xml"),node->getAbsolutePosition());
}

WeaponPickup::~WeaponPickup()
{

}

void WeaponPickup::Update(u32 frameDeltaTime)
{

}

void WeaponPickup::kill()
{
	if (isAlive)
	{
		//ISceneNode *Node = static_cast<ISceneNode *>(body->getUserPointer());
		isAlive = false;
		node->setVisible(false);
		body->setActivationState(0);
		body->setCollisionFlags(4);
		node->setName("dead");
		effect->psNode->clearParticles();
		effect->psNode->setVisible(false);
		effect->psNode->remove();
	}	
}

void WeaponPickup::revive()
{

}

void WeaponPickup::Initialize()
{

}


