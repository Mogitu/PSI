#include <irrlicht.h>
#include <iostream>
#include "Level.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main()
{
	
	IrrlichtDevice *device =
		createDevice(video::EDT_OPENGL, dimension2d<u32>(640, 480), 16,
		false, false, false, 0);

	if (!device)
		return 1;	

	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");	

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World! This is the Irrlicht OPENGL renderer!",
		rect<s32>(10, 10, 260, 22), true);

	scene::ICameraSceneNode * camera = smgr->addCameraSceneNodeFPS(0, 50.f, 0.1f);
	camera->setPosition(core::vector3df(0, 5, 0));

	Level level(smgr,camera,"../Assets/level.irr");	
	
	scene::ISceneNode *pl = level.getNamedNode("BOX");	
	pl->setPosition(core::vector3df(0,30,0));

	u32 then = device->getTimer()->getTime();
	while (device->run())
	{	
		// Work out a frame delta time.
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;
		
		core::vector3df pos = pl->getPosition();

		pos.Y -= 5 * frameDeltaTime;

		pl->setPosition(pos);

		driver->beginScene(true, true, SColor(255, 100, 101, 140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
	
	device->drop();

	return 0;
}
