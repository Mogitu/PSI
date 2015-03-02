#include "Player.h"

Player::Player(ISceneManager* smgr, IVideoDriver* driver, InputReceiver* input, io::path meshName, io::path textureName, vector3df position) : AnimatedModel(smgr, driver, meshName, textureName, position)
{
	this->Initialize(input);
}

Player::Player(ISceneManager* smgr, IVideoDriver* driver, InputReceiver* input, io::path meshName, io::path textureName, vector3df position, vector3df rotation) : AnimatedModel(smgr, driver, meshName, textureName, position, rotation)
{
	this->Initialize(input);
}

Player::Player(ISceneManager* smgr, IVideoDriver* driver, InputReceiver* input, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale) : AnimatedModel(smgr, driver, meshName, textureName, position, rotation, scale)
{
	this->Initialize(input);
}

void Player::Initialize(InputReceiver* input)
{
	this->input = input;
}

void Player::Update(f32 frameDeltaTime)
{
	PlayerMovement(frameDeltaTime);
}

void Player::PlayerMovement(f32 frameDeltaTime)
{
	vector3df vel;

	if (input->IsKeyDown(KEY_KEY_W))
		vel.Z += movement_Speed * frameDeltaTime;
	else if (input->IsKeyDown(KEY_KEY_S))
		vel.Z -= movement_Speed * frameDeltaTime;

	if (input->IsKeyDown(KEY_KEY_A))
		vel.X -= movement_Speed * frameDeltaTime;
	else if (input->IsKeyDown(KEY_KEY_D))
		vel.X += movement_Speed * frameDeltaTime;

	this->addVelocity(vel);

	UpdatePos();
}