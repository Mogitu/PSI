#include "irrlicht.h"
#include "Enemy.h"

using namespace irr;
using namespace scene;
using namespace core;
using namespace video;

Enemy::Enemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, io::path meshpath, io::path texturepath, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->Initialize(smgr, irrDriver, helper, world, meshpath, texturepath, bodyType, bodyMass, position, rotation, scale);
	this->world = world;
	isAlive = true;
}

void Enemy::Initialize(){
	
}

void Enemy::Initialize(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, io::path meshpath, io::path texturepath, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->helper = helper;
	this->smgr = smgr;
	this->irrDriver = irrDriver;


	IAnimatedMesh* mesh = smgr->getMesh(meshpath);

	//default node setup
	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("Enemy");
	if (node)
	{
		node->setPosition(position);
		node->setRotation(rotation);
		node->setScale(scale);
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMaterialTexture(0, irrDriver->getTexture(texturepath));
	}

	body = helper->createBody(node, bodyType, bodyMass);

	body->setRestitution(.1);
	body->setFriction(.3);
	//body->setLinearFactor(btVector3(0, 1, 0));
	body->setAngularFactor(btVector3(0, 0, 0));

	world->addGameObject(this);

}

void Enemy::Update(u32 frameDeltaTime)
{

}

void Enemy::SetDeath(float begindeath, float enddeath, float deathspeed)
{
	this->begindeath = begindeath;
	this->enddeath = enddeath;
	this->deathspeed = deathspeed;
}

void Enemy::getcurrentframe()
{
	frameget = ((IAnimatedMeshSceneNode*)node)->getFrameNr();
}

void Enemy::kill()
{
	
			ISceneNode *Node = static_cast<ISceneNode *>(body->getUserPointer());
			isAlive = false;
			Node->remove();
			// Remove the object from the world
			helper->getWorld()->removeRigidBody(body);
			// Free memory
			delete body->getMotionState();
			delete body->getCollisionShape();
			delete body;
		
	
}