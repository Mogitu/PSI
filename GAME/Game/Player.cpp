#include "Player.h"
#include <iostream>

Player::Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->Initialize(smgr, driver, helper, world, input, meshName, textureName, bodyType, bodyMass, position, rotation, scale);
	this->world = world;
	isAlive = true;
}

void Player::Initialize()
{
	//Overload this function
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

	if (node)
	{
		node->setPosition(position);
		node->setRotation(rotation);
		node->setScale(scale);
		
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, driver->getTexture(textureName));
	}
	
	body = helper->createBody(node, bodyType, bodyMass);

	body->setRestitution(.1);
	body->setFriction(.3);
	//body->setLinearFactor(btVector3(0, 1, 0));
	body->setAngularFactor(btVector3(0, 0, 0));

	world->addGameObject(this);
}

void Player::Update(u32 frameDeltaTime)
{
	PlayerMovement(frameDeltaTime);
	Fire();

	node->updateAbsolutePosition();
}

void Player::PlayerMovement(u32 frameDeltaTime)
{
	btVector3 vel(0, 0, 0);
	btVector3 turningVel(0, 0, 0);
	btVector3 forward = helper->extractForwardVector(this->body);
	this->body->setAngularVelocity(btVector3(0, 0, 0));

	//TODO: Needs more restriction (now you can move while you're not grounded)
	if (input->IsKeyDown(KEY_KEY_W))
		vel = forward * 50;
	else if (input->IsKeyDown(KEY_KEY_S))
		vel = forward * -50;

	int diff = 0;
	
	if (centerScreenPosition.X != input->GetMouseState().Position.X + 5)
		diff = -(centerScreenPosition.X - (input->GetMouseState().Position.X + 5)) / 2;

	turningVel = btVector3(0, diff, 0);

	//TODO: Justjumped isn't used now
	if (input->IsKeyDown(KEY_SPACE) && isGrounded() && !justJumped)
	{
		vel += btVector3(0, 2000, 0);
		//justJumped = true;
	}

	body->setAngularVelocity(turningVel);
	body->applyCentralImpulse(vel);
}

void Player::Fire()
{
	if (input->IsKeyDown(KEY_KEY_E))
	{
		Projectile *p = new Projectile(smgr, helper);
		p->fire(body->getWorldTransform().getOrigin() + helper->extractForwardVector(body)*30, helper->extractForwardVector(body));
		world->addGameObject(p);	
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
	//h->deactivateObject(body);
	ISceneNode *Node = static_cast<ISceneNode *>(body->getUserPointer());
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

GameObjectType Player::getType()
{
	return GameObjectType::PLAYER;
}

IAnimatedMeshSceneNode* Player::getNode()
{
	return node;
}