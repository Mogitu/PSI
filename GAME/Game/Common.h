#ifndef COMMON_H
#define COMMON_H

#include <irrlicht.h>
#include <irrKlang.h>
#include "InputReceiver.h"
#include "BulletHelper.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;
using namespace irrklang;

namespace Common
{
	extern IrrlichtDevice *device;
	extern IVideoDriver *irrDriver;
	extern ISceneManager *smgr;
	extern IGUIEnvironment *guiEnv;
	extern IFileSystem *irrFile;
	extern ITimer *irrTimer;
	extern ILogger *irrLog;
	extern InputReceiver* input;
	extern BulletHelper* helper;
	extern ISoundEngine *soundEngine;

	static void initIrrlicht()
	{
		device = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 32, false, false, false, input);
		guiEnv = device->getGUIEnvironment();
		irrTimer = device->getTimer();
		smgr = device->getSceneManager();
		irrDriver = device->getVideoDriver();
		device->getCursorControl()->setVisible(0);
		soundEngine = irrklang::createIrrKlangDevice();
		device->getCursorControl()->setPosition(0.5f, 0.5f);
		input->MouseState.Position.set(device->getCursorControl()->getPosition().X, device->getCursorControl()->getPosition().Y);
	}
};
#endif