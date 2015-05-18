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
	shootTimerMax = 1.5;
	shootFollowRange = 200;
	walkSpeed = 75;	
	body->setActivationState(DISABLE_DEACTIVATION);
	avoidStrength = 2;
	avoidance = btVector3(0, 0, 0);
	direction = btVector3(0, 0, 0);

}

Enemy::Enemy(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, scene::IAnimatedMeshSceneNode *mesh, Shape_Type bodyType, btScalar bodyMass , vector3df position , vector3df rotation, vector3df scale)
{
	this->Initialize(smgr, irrDriver, helper, world, mesh, bodyType, bodyMass, position, rotation, scale);
	this->world = world;
	player = world->getPlayer();
	isAlive = true;
	shootTimer = 0;
	shootTimerMax = 5;
	shootFollowRange = 200;
	walkSpeed = 75;
	body->setActivationState(DISABLE_DEACTIVATION);
	avoidStrength = 2;
	avoidance = btVector3(0, 0, 0);
	direction = btVector3(0, 0, 0);
}


void Enemy::Initialize(){
	
}

void Enemy::Initialize(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* irrDriver, BulletHelper* helper, GameWorld* world, scene::IAnimatedMeshSceneNode *mesh, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->helper = helper;
	this->smgr = smgr;
	this->irrDriver = irrDriver;
	
	//default node setup
	node = mesh;
	node->setName("Enemy");
	if (node)
	{
		node->setPosition(position);
		node->setRotation(rotation);
		node->setScale(scale);
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMaterialTexture(0, mesh->getMaterial(0).getTexture(0));
	}
	body = helper->createBody(node, bodyType, bodyMass);
	body->setRestitution(.1);
	body->setFriction(.3);
	//body->setLinearFactor(btVector3(0, 1, 0));
	body->setAngularFactor(btVector3(0, 0, 0));
	world->addGameObject(this);

	//WeaponBehaviour
	setWeapon(new FireWeapon());
	getWeapon()->Initialize(new SingleShotBehaviour(), world, 1500);
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

	//WeaponBehaviour
	setWeapon(new FireWeapon());
	getWeapon()->Initialize(new SingleShotBehaviour(), world, 1500);
}

void Enemy::Update(u32 frameDeltaTime)
{	
	if (player && player->isAlive)
	{
		shootTimer += frameDeltaTime;
		//get distance between player and enemy
		f32 dist = node->getPosition().getDistanceFrom(player->node->getPosition());
		//if player is in range the enemy will shoot and attempt to follow at the same time.
		if (player && player->isAlive && dist <= shootFollowRange)
		{
			getWeapon()->Update(frameDeltaTime);
			shoot();
			followPlayer();
		}

		updateAvoidanceSpeed();
		moveEnemy(dist);
	}	
}

//TODO: make more readable...
void Enemy::shoot()
{		
		btVector3 pos(body->getWorldTransform().getOrigin().getX(), body->getWorldTransform().getOrigin().getY() + 20, body->getWorldTransform().getOrigin().getZ());
		btVector3 offSet((btVector3(player->node->getPosition().X, 50, player->node->getPosition().Z) - btVector3(node->getPosition().X, 50, node->getPosition().Z)).normalize() * 30);
		vector3df playerToEnemy = (player->node->getPosition() - node->getPosition()) - vector3df(offSet.getX(), offSet.getY(), offSet.getZ());
		playerToEnemy.normalize();
		btVector3 dir(playerToEnemy.X, playerToEnemy.Y, playerToEnemy.Z);

		if (getWeapon() != NULL)
			getWeapon()->fire(pos + offSet, direction, "EnemyProjectile");
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
		//Get transforms from the bodys
		btTransform playerTransform = player->body->getCenterOfMassTransform();
		btTransform currentTrans = body->getCenterOfMassTransform();

		//Get the direction to move to by normalizing the difference between player and enemy.
		direction = btVector3(player->node->getPosition().X, 50, player->node->getPosition().Z) - btVector3(node->getPosition().X, 50, node->getPosition().Z).normalize();

		//Enemy follows only in the XZ plane
		f32 deltaX = player->node->getPosition().X - node->getPosition().X;
		f32 deltaZ = player->node->getPosition().Z - node->getPosition().Z;

		//atan2 is used to map 360 degrees movement correctly.
		f32 angleInRad = atan2(deltaZ, deltaX);		
		
		btQuaternion rotation;
		//set the rotation to occur around the Y axis, the angle is negative to account for a counter clockwise rotation
		rotation.setRotation(btVector3(0, 1, 0), -angleInRad);

		//apply made rotation
		currentTrans.setRotation(rotation);

		//set all calculations to the body.
		body->setCenterOfMassTransform(currentTrans);
		//body->applyCentralImpulse(helper->extractForwardVector(body)*walkSpeed);
		//body->setLinearVelocity(helper->extractForwardVector(body) * walkSpeed);
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
	avoidance *= avoidStrength;
}

void Enemy::addAvoidance(vector3df delta)
{
	delta *= -1;
	avoidance += btVector3(delta.X, delta.Y, delta.Z);
}

void Enemy::resetAvoidance()
{
	avoidance.setValue(0, 0, 0);
}

void Enemy::moveEnemy(f32 dist)
{
	//TODO: Make this nicer (dist check is already been done in update)
	if (dist <= shootFollowRange)
		body->setLinearVelocity((helper->extractForwardVector(body) + avoidance).normalize() * walkSpeed);
	else
		body->setLinearVelocity((avoidance.length() == 0 ? avoidance : avoidance.normalize()) * walkSpeed);
}

GameObjectType Enemy::getType() const
{
	return GameObjectType::ENEMY;
}