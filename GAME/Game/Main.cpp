#include <irrlicht.h>
#include "BulletHelper.h"
#include  "Level.h"
#include <cstdlib>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

IrrlichtDevice *device;
IVideoDriver *irrDriver;
ISceneManager *smgr;
IGUIEnvironment *irrGUI;
IFileSystem *irrFile;
ITimer *irrTimer;
ILogger *irrLog;

Level *level;
BulletHelper* helper;

int main() {
	// Initialize irrlicht	
	device = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, 0);
	irrGUI = device->getGUIEnvironment();
	irrTimer = device->getTimer();
	smgr = device->getSceneManager();
	irrDriver = device->getVideoDriver();
	device->getCursorControl()->setVisible(0);
	
	// Add camera
	ICameraSceneNode *Camera = smgr->addCameraSceneNodeFPS(0, 100, 0.1);
	Camera->setPosition(vector3df(0, 5, -5));
	Camera->setTarget(vector3df(0, 0, 0));	

	level = new Level(smgr, "../Assets/level.irr");
	
	// Create text
	IGUISkin *Skin = irrGUI->getSkin();
	Skin->setColor(EGDC_BUTTON_TEXT, SColor(255, 255, 255, 255));
	irrGUI->addStaticText(L"Hit 1 to create a box\nHit 2 to create a sphere\nHit x to reset", rect<s32>(0, 0, 200, 100), false);

	// Create the initial scene
	smgr->addLightSceneNode(0, core::vector3df(2, 5, -2), SColorf(4, 4, 4, 1));	

	helper = new BulletHelper(device);
	helper->buildIrrLevel(level);	
	
	// Main loop
	u32 TimeStamp = irrTimer->getTime(), DeltaTime = 0;
	while (device->run()) {
		DeltaTime = irrTimer->getTime() - TimeStamp;
		TimeStamp = irrTimer->getTime();
		helper->UpdatePhysics(DeltaTime);
		irrDriver->beginScene(true, true, SColor(255, 20, 0, 0));
		smgr->drawAll();
		irrGUI->drawAll();
		irrDriver->endScene();
		device->run();
	}
	device->drop();

	return 0;
}










