#include <irrlicht.h>
#include <cstdlib>
#include "BulletHelper.h"
#include "Level.h"
#include "GameWorld.h"
#include "InputReceiver.h"
#include "Projectile.h"
#include "Player.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main() {

	list<Projectile*> projectiles;

	IrrlichtDevice *device;
	IVideoDriver *irrDriver;
	ISceneManager *smgr;
	IGUIEnvironment *guiEnv;
	IFileSystem *irrFile;
	ITimer *irrTimer;
	ILogger *irrLog;
	Level *level;
	BulletHelper* helper;
	InputReceiver* input = new InputReceiver();

	// Initialize irrlicht	
	device = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, input);
	guiEnv = device->getGUIEnvironment();
	irrTimer = device->getTimer();
	smgr = device->getSceneManager();
	irrDriver = device->getVideoDriver();
	device->getCursorControl()->setVisible(0);

	// Add camera
	ICameraSceneNode *camera = smgr->addCameraSceneNodeFPS(0, 100, 0.1);
	camera->setPosition(vector3df(-161, 100, -150));
	camera->setTarget(vector3df(0, 0, 0));
	
	level = new Level(smgr, "../Assets/level.irr");	

	// Create the initial scene
	smgr->addLightSceneNode(0, core::vector3df(2, 5, -2), SColorf(4, 4, 4, 1));

	helper = new BulletHelper();
	helper->buildIrrLevel(level);
<<<<<<< HEAD
	
	//Default mesh from demos
	IMesh* mesh = smgr->getMesh("../Assets/sydney.md2");		
	
	//default node setup
	IMeshSceneNode* node = smgr->addMeshSceneNode(mesh);	
	node->setMaterialTexture(0, irrDriver->getTexture("../Assets/sydney.bmp"));	
	node->setPosition(vector3df(0,50,0));		
=======
>>>>>>> origin/Player

	//Create the game world
	GameWorld* gWorld = new GameWorld();
	Player* player = new Player(smgr, irrDriver, helper, gWorld, input, "../Assets/sydney.md2", "../Assets/sydney.bmp", Shape_Type::CAPSULE, 80, vector3df(0, 100, 0));

	camera->setTarget(player->getNodePosition());
	
	// Main loop
	u32 timeStamp = irrTimer->getTime(), deltaTime = 0;
	while (device->run()) {
		//basic stuff
		deltaTime = irrTimer->getTime() - timeStamp;
		timeStamp = irrTimer->getTime();

		gWorld->update(deltaTime);
		helper->updatePhysics(deltaTime);

		irrDriver->beginScene(true, true, SColor(255, 20, 0, 0));
		smgr->drawAll();
		guiEnv->drawAll();
<<<<<<< HEAD
		irrDriver->endScene();	

		//Update input and player
		if (b)
		{
			b->setAngularVelocity(btVector3(0, 0, 0));
			if (receiver.IsKeyDown(irr::KEY_KEY_W))
			{
				b->applyCentralImpulse(helper->extractForwardVector(b) * 2000);
			}
			else if (receiver.IsKeyDown(irr::KEY_KEY_S))
			{

				b->applyCentralImpulse(-helper->extractForwardVector(b) * 2000);
			}

			if (receiver.IsKeyDown(irr::KEY_KEY_A))
			{

				b->setAngularVelocity(btVector3(0, -5, 0));
			}
			else if (receiver.IsKeyDown(irr::KEY_KEY_D))
			{
				b->setAngularVelocity(btVector3(0, 5, 0));
			}

			if (receiver.IsKeyDown(irr::KEY_KEY_Q))
			{
				b->applyCentralImpulse(btVector3(0, 6000, 0));
			}

			if (receiver.IsKeyDown(irr::KEY_KEY_E))
			{								
					Projectile *p = new Projectile(smgr, helper);
					p->fire(b->getWorldTransform().getOrigin() + helper->extractForwardVector(b) * 40, helper->extractForwardVector(b));
					projectiles.push_back(p);
			}			

			for (list<Projectile *>::Iterator Iterator = projectiles.begin(); Iterator != projectiles.end(); ++Iterator) {
				Projectile *Object = *Iterator;
				Object->update(deltaTime);
			}
		}	
=======
		irrDriver->endScene();

		//Close Device
		if (input->IsKeyDown(EKEY_CODE::KEY_ESCAPE))
			device->closeDevice();
>>>>>>> origin/Player
	}
	device->drop();
	return 0;
}










