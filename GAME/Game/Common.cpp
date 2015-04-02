#include "Common.h"

namespace Common
{
	IrrlichtDevice *device;
	IVideoDriver *irrDriver;
	ISceneManager *smgr;
	IGUIEnvironment *guiEnv;
	IFileSystem *irrFile;
	ITimer *irrTimer;
	ILogger *irrLog;
	InputReceiver* input = new InputReceiver();
	BulletHelper* helper;
	ISoundEngine *soundEngine;
}