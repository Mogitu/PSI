#include <irrlicht.h>
#include <cstdlib>
#include "BulletHelper.h"
#include "Level.h"
#include "GameWorld.h"
#include "InputReceiver.h"
#include "Projectile.h"
#include "Player.h"
#include <math.h> 

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;

//Camera
ICameraSceneNode *camera;
//needed to see the mousemovement
vector2di middleScreenPosition;
vector2di cursorChange;
//add some limitations to the y rotation (0) and (0.45f)
f32 yMin = 0;
f32 yMax = 0.45f;
//current angle of the camera
f32 angle = 0;
//rotate speed (0.05)
f32 yRotateSpeed = 0.05;
//if the pivot of the node to follow is to low/high, you can adjust it with heightmodifier(50)
f32 heightModifier = 50;
//distance to the node(100)
f32 cameradistance = 100;
//fps, has nothing to do with cameras but is needed since way to much fps makes the camera a bit laggy(60)
u32 fps = 60;

void updateCamera(IrrlichtDevice *device,vector3df nodePosition,f32 frameDeltaTime, Player *p, BulletHelper *h)
{
	/*
	//get the change of position since the last frame
	cursorChange = middleScreenPosition.operator-(device->getCursorControl()->getPosition());
	//reset the position to the middle of the screen
	device->getCursorControl()->setPosition(0.5f, 0.5f);
	//retarget the camera since the player could have moved
	camera->setTarget(vector3df(0, heightModifier, 0));
	//angle stuff
	angle += ((f32)cursorChange.Y)*frameDeltaTime / 1000*yRotateSpeed;
	if (angle > yMax)angle = yMax;
	if (angle < yMin)angle = yMin;
	//get the old position of the camera
	vector3df pos = camera->getPosition();
	pos = vector3df(-cos(angle), sin(angle), 0);
	pos.operator*=(cameradistance);
	//if needed, the x rotation
	pos.rotateXZBy(cursorChange.X * frameDeltaTime, nodePosition);
	//reposition the camera
	camera->setPosition(pos.operator+(vector3df(0, heightModifier, 0)));
	//retarget to change the rotation
	camera->setTarget(vector3df(0, heightModifier, 0));	
	//std::cout << pos.X << "," << pos.Y << "," << pos.Z << " en " << pos.getLength() << " en " << angle << " en " << (f32)cursorChange.Y << endl;
	*/
	camera->setRotation(p->getNode()->getRotation());
	vector3df forward(h->extractForwardVector(p->body).getX(), h->extractForwardVector(p->body).getY(), h->extractForwardVector(p->body).getZ());
	vector3df newPos(p->getNodePosition() - forward * cameradistance);
	camera->setPosition(vector3df(newPos.X, newPos.Y+heightModifier, newPos.Z));
	camera->setTarget(p->getNodePosition());
}



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
	camera = smgr->addCameraSceneNode(0);
	
	device->getCursorControl()->setPosition(0.5f, 0.5f);
	middleScreenPosition = device->getCursorControl()->getPosition();
	
	level = new Level(smgr, "../Assets/level.irr");	

	// Create the initial scene
	smgr->addLightSceneNode(0, core::vector3df(2, 5, -2), SColorf(4, 4, 4, 1));

	helper = new BulletHelper();
	helper->buildIrrLevel(level);

	//Create the game world
	GameWorld* gWorld = new GameWorld();
	Player* player = new Player(smgr, irrDriver, helper, gWorld, input, "../Assets/sydney.md2", "../Assets/sydney.bmp", Shape_Type::CAPSULE, 80, vector3df(0, 100, 0));

	// Main loop
	u32 timeStamp = irrTimer->getTime(), deltaTime = 0;
	while (device->run()) {
		//basic stuff
		deltaTime = irrTimer->getTime() - timeStamp;
		//applying the fps
		if (deltaTime < 1000/fps)
			continue;
		timeStamp = irrTimer->getTime();

		gWorld->update(deltaTime);		
		updateCamera(device, player->getNodePosition(), (f32)deltaTime, player, helper);
		helper->getWorld()->stepSimulation(deltaTime * 0.001f, 60);
		gWorld->update(deltaTime);

		irrDriver->beginScene(true, true, SColor(255, 20, 0, 0));
		smgr->drawAll();
		guiEnv->drawAll();
		irrDriver->endScene();	
		//Close Device
		if (input->IsKeyDown(EKEY_CODE::KEY_ESCAPE))
			device->closeDevice();
	}

	device->drop();
	return 0;
}










