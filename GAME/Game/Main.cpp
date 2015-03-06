#include <irrlicht.h>
#include "BulletHelper.h"
#include  "Level.h"
#include <cstdlib>
#include "Projectile.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class MyEventReceiver : public IEventReceiver
{
public:
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	{
		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

		return false;
	}

	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}

	MyEventReceiver()
	{
		for (u32 i = 0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}

private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

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
	MyEventReceiver receiver;

	// Initialize irrlicht	
	device = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, &receiver);
	guiEnv = device->getGUIEnvironment();
	irrTimer = device->getTimer();
	smgr = device->getSceneManager();
	irrDriver = device->getVideoDriver();
	device->getCursorControl()->setVisible(0);
	
	// Add camera
	ICameraSceneNode *camera = smgr->addCameraSceneNodeFPS(0, 100, 0.1);
	//camera->setPosition(vector3df(-161, 100, -300));
	camera->setPosition(vector3df(0,30,-150));	
	
	level = new Level(smgr, "../Assets/level.irr");	

	// Create the initial scene
	smgr->addLightSceneNode(0, core::vector3df(2, 5, -2), SColorf(4, 4, 4, 1));	

	helper = new BulletHelper();
	helper->buildIrrLevel(level);
	
	//Default mesh from demos
	IMesh* mesh = smgr->getMesh("../Assets/sydney.md2");		
	
	//default node setup
	IMeshSceneNode* node = smgr->addMeshSceneNode(mesh);	
	node->setMaterialTexture(0, irrDriver->getTexture("../Assets/sydney.bmp"));	
	node->setPosition(vector3df(0,50,0));		

	//createa a new rigidbody from earlier made node
	btRigidBody *b =helper->createBody(node,Shape_Type::CAPSULE, 10000);	

	camera->setTarget(node->getPosition());

	b->setAngularFactor(btVector3(0,1,0));
	b->setInterpolationLinearVelocity(btVector3(100,0,0));
	b->setRestitution(0);
	b->setFriction(2);
	


	// Main loop
	u32 timeStamp = irrTimer->getTime(), deltaTime = 0;
	while (device->run()) {
		//basic stuff
		deltaTime = irrTimer->getTime() - timeStamp;
		timeStamp = irrTimer->getTime();
		helper->updatePhysics(deltaTime);
		irrDriver->beginScene(true, true, SColor(255, 20, 0, 0));
		smgr->drawAll();
		guiEnv->drawAll();
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
	}
	device->drop();
	return 0;
}











