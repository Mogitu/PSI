#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "AnimatedModel.h"
#include "InputReceiver.h"

class Player : public AnimatedModel
{
private:
	InputReceiver* input;
	f32 const movement_Speed = 100.f;
public:
	Player(ISceneManager* smgr, IVideoDriver* driver, InputReceiver* input, io::path meshName, io::path textureName, vector3df position);
	Player(ISceneManager* smgr, IVideoDriver* driver, InputReceiver* input, io::path meshName, io::path textureName, vector3df position, vector3df rotation);
	Player(ISceneManager* smgr, IVideoDriver* driver, InputReceiver* input, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale);
	void Initialize(InputReceiver* input);
	void Update(f32 frameDeltaTime);
	void PlayerMovement(f32 frameDeltaTime);
};

#endif // !__PLAYER_H__
