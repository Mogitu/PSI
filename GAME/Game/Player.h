#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "AnimatedModel.h"

class Player : public AnimatedModel
{
public:
	Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position);
	Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation);
	Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale);
	void Update();
};

#endif // !__PLAYER_H__
