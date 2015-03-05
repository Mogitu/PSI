#include "Player.h"

Player::Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->Initialize(smgr, driver, helper, input, meshName, textureName, bodyType, bodyMass, position, rotation, scale);
}

void Player::Initialize()
{
	//Overload this function
}

void Player::Initialize(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->input = input;
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
}

void Player::Update(u32 frameDeltaTime)
{
	PlayerMovement(frameDeltaTime);
}

void Player::PlayerMovement(u32 frameDeltaTime)
{
	btVector3 vel(0,0,0);

	//Needs more restriction (now you can move while you're not grounded)

	if (input->IsKeyDown(KEY_KEY_W))
		vel += btVector3(0, 0, 50);
	else if (input->IsKeyDown(KEY_KEY_S))
		vel += btVector3(0, 0, -50);

	if (input->IsKeyDown(KEY_KEY_A))
		vel += btVector3(-50, 0, 0);
	else if (input->IsKeyDown(KEY_KEY_D))
		vel += btVector3(50, 0, 0);

	
	if (input->IsKeyDown(KEY_SPACE))
		vel += btVector3(0, 500, 0);

	body->applyCentralForce(vel);
}

GameObjectType Player::getType()
{
	return GameObjectType::PLAYER;
}