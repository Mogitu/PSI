#ifndef COMMON_H
#define COMMON_H

#include <irrlicht.h>
#include "InputReceiver.h"
#include "BulletHelper.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;

namespace Common
{
	static IrrlichtDevice *device;
	static IVideoDriver *irrDriver;
	static ISceneManager *smgr;
	static IGUIEnvironment *guiEnv;
	static IFileSystem *irrFile;
	static ITimer *irrTimer;
	static ILogger *irrLog;
	static InputReceiver* input = new InputReceiver();
	static BulletHelper* helper;

	static void initIrrlicht()
	{
		device = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, input);
		guiEnv = device->getGUIEnvironment();
		irrTimer = device->getTimer();
		smgr = device->getSceneManager();
		irrDriver = device->getVideoDriver();
		device->getCursorControl()->setVisible(0);

		device->getCursorControl()->setPosition(0.5f, 0.5f);
		input->MouseState.Position.set(device->getCursorControl()->getPosition().X, device->getCursorControl()->getPosition().Y);
	}
};
#endif