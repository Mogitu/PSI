#include "Player.h"

Player::Player(ISceneManager* smgr, IVideoDriver* driver, BulletHelper* helper, InputReceiver* input, io::path meshName, io::path textureName, Shape_Type bodyType, btScalar bodyMass, vector3df position, vector3df rotation, vector3df scale)
{
	this->Initialize(smgr, driver, helper, input, meshName, textureName, bodyType, bodyMass, position, rotation, scale);
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
}

void Player::Update(f32 frameDeltaTime)
{
	PlayerMovement(frameDeltaTime);
}

void Player::PlayerMovement(f32 frameDeltaTime)
{

	//if (input->IsKeyDown(KEY_KEY_W))
	//	body->setLinearVelocity(btVector3(50, 0, 0));
	/*else if (input->IsKeyDown(KEY_KEY_S))

	if (input->IsKeyDown(KEY_KEY_A))
	else if (input->IsKeyDown(KEY_KEY_D))
	*/

}