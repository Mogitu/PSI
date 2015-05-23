#include "WeaponPickup.h"


WeaponPickup::WeaponPickup(irr::core::stringw name,BulletHelper *h, irr::scene::ISceneNode *m)
{
	node = m;
	node->setName(name);
	body = h->createBody(node,Shape_Type::BOX,0);
	isAlive = true;
}

WeaponPickup::~WeaponPickup()
{

}

void WeaponPickup::Update(u32 frameDeltaTime)
{

}

void WeaponPickup::kill()
{
	ISceneNode *Node = static_cast<ISceneNode *>(body->getUserPointer());
	isAlive = false;
	Node->setVisible(false);
	body->setActivationState(0);
	body->setCollisionFlags(4);
	node->setName("dead");
}

void WeaponPickup::revive()
{

}

void WeaponPickup::Initialize()
{

}


