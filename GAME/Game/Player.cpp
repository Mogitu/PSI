#include "Player.h"

Player::Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position) : AnimatedModel(smgr, driver, meshName, textureName, position)
{
	//Init player specific variables
}

Player::Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation) : AnimatedModel(smgr, driver, meshName, textureName, position, rotation)
{
	//Init player specific variables
}

Player::Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale) : AnimatedModel(smgr, driver, meshName, textureName, position, rotation, scale)
{
	//Init player specific variables
}