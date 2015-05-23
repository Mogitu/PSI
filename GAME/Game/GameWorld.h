#ifndef Game_World_H
#define Game_World_H

#include <irrlicht.h>
#include "IGameObject.h"
#include "BulletHelper.h"
#include "ParticleManager.h"
#include "Projectile.h"
#include "Level.h"
#include "InputReceiver.h"
#include "Menu.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

using namespace irr;

enum GAMESTATE
{
	PLAYING,
	PAUSED,
	GAMEOVER,
	LEVELCOMPLETE
};

class GameWorld
{
	
private:
	//constants for objects in a level
	const std::string DYNAMIC_SPHERE = "DS";
	const std::string DYNAMIC_CUBE = "DB";
	const std::string STATIC_SPHERE = "SS";
	const std::string STATIC_CUBE = "SB";
	const std::string WORLD = "WB";
	const std::string PARTICLE = "PS";
	const std::string ENEMY = "EN";
	const std::string FIREENEMY = "FE";
	const std::string ICEENEMY = "IE";
	const std::string WINDENEMY = "WE";
	const std::string PLAYER = "PL";
	const std::string FIREWEAPON = "FW";
	const std::string ICEWEAPON = "IW";
	const std::string WINDWEAPON = "WW";

	InputReceiver *playerInputReceiver;
	core::list<IGameObject*> gameObjects;
	BulletHelper *helper;
	IrrlichtDevice *device;
	IGameObject *player;
	Menu *menu;

public:
	GameWorld(BulletHelper *h, IrrlichtDevice *device);
	GameWorld(BulletHelper *h, IrrlichtDevice *device, InputReceiver *playerInputReceiver);


	~GameWorld();
	void clearGameObjects();
	void update(u32 frameDeltaTime);
	void restart(Level *level);
	//void updatePhysics(btRigidBody *body);
	void addGameObject(IGameObject* gameObject);
	void removeGameObject(IGameObject* gameObject);
	void setPlayer(IGameObject *p);
	IGameObject *getPlayer();
	void buildIrrLevel(Level *level);	
	GAMESTATE gameState;
};

#endif // !Game_World_H
