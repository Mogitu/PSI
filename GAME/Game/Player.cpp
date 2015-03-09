#include "Player.h"
#include <iostream>

Player::Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, GameWorld* world, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->Initialize(smgr, driver, helper, world, input, meshName, textureName, bodyType, bodyMass, position, rotation, scale);
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
	p = new Projectile(smgr, helper);
	oldMousePos = input->GetMouseState().Position;

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

	oldMousePos = input->GetMouseState().Position;
}

void Player::PlayerMovement(u32 frameDeltaTime)
{
	btVector3 vel(0, 0, 0);
	btVector3 turningVel(0, 0, 0);
	btVector3 forward = helper->extractForwardVector(this->body);
	this->body->setAngularVelocity(btVector3(0, 0, 0));
	
	//TODO: Needs more restriction (now you can move while you're not grounded)
	if (input->IsKeyDown(KEY_KEY_W))
		vel = forward * 5;
	else if (input->IsKeyDown(KEY_KEY_S))
		vel = forward * -5;

	if (input->IsKeyDown(KEY_KEY_A))
		turningVel = btVector3(0, -5, 0);
	else if (input->IsKeyDown(KEY_KEY_D))
		turningVel = btVector3(0, 5, 0);

	//TODO: Justjumped isn't used now
	if (input->IsKeyDown(KEY_SPACE) && isGrounded() && !justJumped)
	{
		vel += btVector3(0, 500, 0);
		//justJumped = true;
	}

	body->setAngularVelocity(turningVel);
	body->applyCentralImpulse(vel);
}

void Player::Fire()
{
	if (input->IsKeyDown(KEY_KEY_E))
	{
		p->fire(body->getWorldTransform().getOrigin(), helper->extractForwardVector(body));
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

vector3df Player::getNodePosition()
{
	return node->getPosition();
}

GameObjectType Player::getType()
{
	return GameObjectType::PLAYER;
}