#include "Player.h"

Player::Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position) : AnimatedModel(smgr, driver, meshName, textureName, position)
{
	//Init player specific variables
}