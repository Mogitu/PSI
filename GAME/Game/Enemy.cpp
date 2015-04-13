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
	player = world->getPlayer();
	isAlive = true;
	shootTimer = 0;
	shootTimerMax = 2;
	shootingRange = 200;
	walkSpeed = 75;
	addAvoidSpeed = 2;
	avoidance = btVector3(0, 0, 0);
	direction = btVector3(0, 0, 0);

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
	shootTimer += frameDeltaTime;	
	if (player && player->isAlive)
	{
		if (shootTimer >= shootTimerMax * 1000 && player)
		{
			shootTimer = 0;
			//shoot();
		}
		followPlayer();
	}

	updateAvoidanceSpeed();
	moveEnemy();
}

//TODO: make more readable...
void Enemy::shoot()
{
	
	f32 dist = node->getPosition().getDistanceFrom(player->node->getPosition());
	if(dist<shootingRange)
	{
		Projectile *projectile = new Projectile(smgr, helper);
		btVector3 pos(body->getWorldTransform().getOrigin().getX(), body->getWorldTransform().getOrigin().getY() + 20, body->getWorldTransform().getOrigin().getZ());
		btVector3 offSet((btVector3(player->node->getPosition().X, 50, player->node->getPosition().Z) - btVector3(node->getPosition().X, 50, node->getPosition().Z)).normalize() * 30);
		vector3df playerToEnemy = (player->node->getPosition() - node->getPosition()) - vector3df(offSet.getX(), offSet.getY(), offSet.getZ());
		playerToEnemy.normalize();
		btVector3 direction(playerToEnemy.X, playerToEnemy.Y, playerToEnemy.Z);
		projectile->fire(pos + offSet, direction);
		world->addGameObject(projectile);
		Common::soundEngine->play2D("../Assets/Sounds/shoot.wav");
	}	
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

void Enemy::followPlayer()
{
	btTransform playerTransform = player->body->getCenterOfMassTransform();
	btTransform currentTrans = body->getCenterOfMassTransform();	

	direction = btVector3(player->node->getPosition().X, 50, player->node->getPosition().Z) - btVector3(node->getPosition().X, 50, node->getPosition().Z).normalize();
	
	f32 deltaX = player->node->getPosition().X - node->getPosition().X;
	f32 deltaZ = player->node->getPosition().Z - node->getPosition().Z;

	f32 angleInRad= atan2(deltaZ, deltaX);

	btQuaternion rot;
	rot.setRotation(btVector3(0,1,0),-angleInRad);
	currentTrans.setRotation(rot);

	body->setCenterOfMassTransform(currentTrans);
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

//flocking separation
void Enemy::updateAvoidanceSpeed()
{
	if (avoidance.length() == 0)
		return;

	avoidance.normalize();
	avoidance *= addAvoidSpeed;
}

void Enemy::addAvoidance(vector3df delta)
{
	delta *= -1;
	avoidance += btVector3(delta.X, delta.Y, delta.Z);
}

void Enemy::resetAvoidance()
{
	avoidance = btVector3(0, 0, 0);
}

void Enemy::moveEnemy()
{
	direction.setY(body->getLinearVelocity().getY());
	body->setLinearVelocity(direction + avoidance * walkSpeed);
}

GameObjectType Enemy::getType() const
{
	return GameObjectType::ENEMY;
}