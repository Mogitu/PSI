#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "AnimatedModel.h"

class Player : public AnimatedModel
{
public:
	Player(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position);
	void Update();
};

#endif // !__PLAYER_H__
