#include "Player.h"
#include <iostream>

Player::Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->Initialize(smgr, driver, helper, world, input, meshName, textureName, bodyType, bodyMass, position, rotation, scale);
	this->world = world;
	isAlive = true;
	shootInterval = 250;//ms
	shootIntervalTimer = 0;
	world->setPlayer(this);
	health = 100;
	score = 0;
	speed = 100;
}

void Player::Initialize()
{
	//Overload this function
}

void Player::increaseScore(int amount)
{
	score += amount;
}

int Player::getScore()
{
	return score;
}

void Player::Initialize(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	justJumped = false;
	this->input = input;
	this->helper = helper;
	this->smgr = smgr;	
	centerScreenPosition = input->GetMouseState().Position;

	IAnimatedMesh* mesh = smgr->getMesh(meshName);
	
	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("Player");
	if (node)
	{
		node->setPosition(position);
		node->setRotation(rotation);
		node->setScale(scale);
		
		node->setMaterialFlag(EMF_LIGHTING, false);
		((IAnimatedMeshSceneNode*)node)->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, driver->getTexture(textureName));
	}
	
	body = helper->createBody(node, bodyType, bodyMass);
	body->setActivationState(DISABLE_DEACTIVATION);
	body->setRestitution(.1);
	body->setFriction(.3);
	//body->setLinearFactor(btVector3(0, 1, 0));
	body->setAngularFactor(btVector3(0, 0, 0));

	world->addGameObject(this);
}

void Player::Update(u32 frameDeltaTime)
{
	//only update when alive
	if (health > 0 && isAlive)
	{
		PlayerMovement(frameDeltaTime);
		shootIntervalTimer += frameDeltaTime;
		if (shootIntervalTimer>shootInterval)
		{
			shootIntervalTimer = 0;
			Fire();
		}
		node->updateAbsolutePosition();
	}
}

void Player::takeDamage(int amount)
{
	health -= amount;
	ParticleManager::createFullParticleEffect("../Assets/bloodsplat.xml", node->getPosition());
	Common::soundEngine->play2D("../Assets/Sounds/splat.wav");
	if (health <= 0)
	{
		world->gameState = GAMESTATE::GAMEOVER;
		isAlive = false;
		node->setName("dead");
		node->setVisible(false);
	}
}


void Player::PlayerMovement(u32 frameDeltaTime)
{
	btVector3 newVel(0, 0, 0);
	btVector3 currentVel(0, 0, 0);
	btVector3 jump(0, 0, 0);
	btVector3 turningVel(0, 0, 0);
	btVector3 forward = helper->extractForwardVector(this->body);
	btVector3 right = helper->extractRightVector(this->body);

	this->body->setAngularVelocity(btVector3(0, 0, 0));

	bool grounded = isGrounded();

	if (grounded)
	{
		restriction = 1;
		currentVel = body->getLinearVelocity();
	}
	else
		restriction = .4f;

	if (input->IsKeyDown(KEY_KEY_W))
		newVel = forward * speed * restriction;
	else if (input->IsKeyDown(KEY_KEY_S))
		newVel = -forward * speed * restriction;

	if (input->IsKeyDown(KEY_KEY_A))
		newVel += right * speed * restriction;
	else if (input->IsKeyDown(KEY_KEY_D))
		newVel += -right * speed * restriction;

	int diff = 0;

	if (centerScreenPosition.X != input->GetMouseState().Position.X + 5)
		diff = -(centerScreenPosition.X - (input->GetMouseState().Position.X + 5)) / 2;

	turningVel = btVector3(0, diff, 0);

	//TODO: Justjumped isn't used now (now the jumps are uneven)
	if (input->IsKeyDown(KEY_SPACE) && grounded && !justJumped)
	{
		jump = btVector3(0, 2000, 0);
	}

	if (grounded)
	{
		newVel.setY(currentVel.getY());
		body->setLinearVelocity(newVel);
	}
	else
	{
		jump += newVel;
	}

	body->applyCentralImpulse(jump);
	body->setAngularVelocity(turningVel);
}

void Player::Fire()
{
	if (input->IsKeyDown(KEY_KEY_E))
	{
		Projectile *p = new Projectile(smgr, helper,"PlayerProjectile");
		btVector3 pos(body->getWorldTransform().getOrigin().getX(), body->getWorldTransform().getOrigin().getY()+20, body->getWorldTransform().getOrigin().getZ());		
		p->fire(pos + helper->extractForwardVector(body)*30, helper->extractForwardVector(body));
		world->addGameObject(p);	
		Common::soundEngine->play2D("../Assets/Sounds/shoot.wav");
	}	
}

bool Player::isGrounded()
{
	btScalar height = node->getTransformedBoundingBox().getExtent().Y;
	btVector3 rFrom = body->getWorldTransform().getOrigin();
	//rFrom.setY(rFrom.getY() - height / 2);
	btVector3 rTo = rFrom;
	//TODO: Remove Hardcode value (22)
	rTo.setY(rTo.getY() - 22);

	btCollisionWorld::ClosestRayResultCallback res(rFrom, rTo);

	helper->getWorld()->rayTest(rFrom, rTo, res);

	if (res.hasHit())
		return true;
	else
		justJumped = false;

	return false;
}

void Player::kill()
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

const vector3df& Player::getNodePosition() const
{
	return node->getPosition();
}

const vector3df& Player::getNodeAbsolutePosition() const
{
	return node->getAbsolutePosition();
}

GameObjectType Player::getType() const
{
	return GameObjectType::PLAYER;
}

IAnimatedMeshSceneNode* Player::getNode()
{
	return (IAnimatedMeshSceneNode*)node;
}