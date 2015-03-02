#include <irrlicht.h>
#include "Player.h"
#include "InputReceiver.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

u32 then;
f32 getFrameDeltaTime(IrrlichtDevice* device)
{
	// Work out a frame delta time.
	const u32 now = device->getTimer()->getTime();
	const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds

	then = now;

	return frameDeltaTime;
}

int main()
{
	InputReceiver input;

	IrrlichtDevice *device =
		createDevice(video::EDT_OPENGL, dimension2d<u32>(640, 480), 16,
		false, false, false, &input);
	
	if (!device)
		return 1;

	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	/*guienv->addStaticText(L"Hello World! This is the Irrlicht OPENGL renderer!",
		rect<s32>(10, 10, 260, 22), true);*/
	Player p(smgr, driver, &input, "../Assets/sydney.md2", "../Assets/sydney.bmp", vector3df());

	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

	then = device->getTimer()->getTime();
	while (device->run())
	{
		driver->beginScene(true, true, SColor(255, 100, 101, 140));

		p.Update(getFrameDeltaTime(device));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();
	}

	device->drop();

	return 0;
}

