#include "Common.h"
#include <cstdlib>
#include "Level.h"
#include "GameWorld.h"
#include "Projectile.h"
#include "Player.h"
#include "ParticleManager.h"
#include <math.h>
#include "Enemy.h"

using namespace Common;

//Camera
ICameraSceneNode *camera;

//needed to see the mousemovement
vector2di middleScreenPosition;
vector2di cursorChange;

//add some limitations to the y rotation (-0.2) and (0.45)
f32 yMin = -0.2;
f32 yMax = 0.45;
//current angle of the camera
f32 angle = 0;
//rotate speed (0.05)
f32 yRotateSpeed = 0.05;
//if the pivot of the node to follow is to low/high, you can adjust it with heightmodifier(35)
f32 heightModifier = 35;
//distance to the node(150)
f32 cameradistance = 150;
//fps, has nothing to do with cameras but is needed since way to much fps makes the camera a bit laggy(60)
u32 fps = 60;

void updateCamera(IrrlichtDevice *device, vector3df nodePosition, f32 frameDeltaTime)
{
	//get the change of position since the last frame
	cursorChange = middleScreenPosition.operator-(device->getCursorControl()->getPosition());

	//reset the position to the middle of the screen
	device->getCursorControl()->setPosition(0.5f, 0.5f);

	//retarget the camera since the player could have moved
	camera->setTarget(nodePosition.operator+(vector3df(0, heightModifier, 0)));

	//angle stuff
	angle += ((f32)cursorChange.Y)*frameDeltaTime / 1000 * yRotateSpeed;
	if (angle > yMax)angle = yMax;
	if (angle < yMin)angle = yMin;
	//get the old position of the camera
	vector3df pos = vector3df(-cos(angle), sin(angle), 0);
	pos.operator*=(cameradistance);
	//if needed, the x rotation
	//pos.rotateXZBy(cursorChange.X * frameDeltaTime, nodePosition);

	//reposition the camera
	camera->setPosition(pos.operator+(vector3df(0, heightModifier, 0)));
	//retarget to change the rotation
	camera->setTarget(nodePosition.operator+(vector3df(0, heightModifier, 0)));
}

//Draw basic hud with score and player health, also displayes game over text when player is dead.
void drawHud(IGUIFont *font, Player *player,GameWorld *world)
{
	//default textcolor, yellow
	SColor textColor(255,255,255,0);
	//player health
	font->draw(L"Health:", rect<s32>(3, 0, 300, 50),textColor);
	stringw playerHealth(player->health);
	font->draw(playerHealth, rect<s32>(70, 0, 300, 50), textColor);
	//score
	stringw playerScore(player->getScore());
	font->draw(L"Score:", rect<s32>(3, 20, 300, 50), textColor);
	font->draw(playerScore, rect<s32>(70, 20, 300, 50), textColor);
	//when gameover
	if (player->health<=0 || !player->isAlive)
	{
		font->draw(L"GAME OVER", rect<s32>(300, 300, 300, 50), textColor);
	}
	if (world->gameState==GAMESTATE::LEVELCOMPLETE)
	{
		font->draw(L"LEVEL COMPLETE!!!", rect<s32>(300, 300, 300, 50), textColor);
	}
}

int main() {
	initIrrlicht();
	// Add camera
	camera = smgr->addCameraSceneNode(0);
	camera->setPosition(vector3df(100, 100, 0));
	device->getCursorControl()->setPosition(0.5f, 0.5f);
	middleScreenPosition = device->getCursorControl()->getPosition();

	Level *level = new Level(smgr, "../Assets/level.irr");

	// Create the initial scene
	smgr->addLightSceneNode(0, core::vector3df(2, 5, -2), SColorf(4, 4, 4, 1));

	helper = new BulletHelper();	

	//Create the game world
	GameWorld* gWorld = new GameWorld(helper,device,input);	
	Player* player = new Player(smgr, irrDriver, helper, gWorld, input, "../Assets/sydney.md2", "../Assets/sydney.bmp", Shape_Type::CAPSULE, 80, vector3df(447, 100, -299));	
	
	gWorld->buildIrrLevel(level);		

	camera->setParent(player->getNode());
	camera->setTarget(player->getNodeAbsolutePosition());
	
	Common::soundEngine->play2D("../Assets/Sounds/darknight.mp3");
	
	//create hud vars.
	IGUIEnvironment *gui = device->getGUIEnvironment();
	IGUIFont *font = gui->getFont("../Assets/Fonts/myfont.xml");
	//ParticleManager::createFullParticleEffect("../Assets/firesea.xml",vector3df(316,40,-200));
	// Main loop
	u32 timeStamp = irrTimer->getTime(), deltaTime = 0;
	while (device->run()) {		
		//basic stuff
		deltaTime = irrTimer->getTime() - timeStamp;
		//applying the fps
		if (deltaTime < 1000 / fps)
			continue;
		timeStamp = irrTimer->getTime();	
		//only update the camera when the player is alive.
		if (player->isAlive && gWorld->gameState==GAMESTATE::PLAYING)
		{
			updateCamera(device, player->getNodeAbsolutePosition(), (f32)deltaTime);
			camera->setTarget(player->getNodeAbsolutePosition());
		}		
		helper->getWorld()->stepSimulation(deltaTime * 0.001f, 60);
		gWorld->update(deltaTime);
		ParticleManager::update(deltaTime);
		irrDriver->beginScene(true, true, SColor(255, 20, 0, 0));
		smgr->drawAll();
		drawHud(font, player,gWorld);
		guiEnv->drawAll();
		irrDriver->endScene();
		//Close Device
		if (input->IsKeyDown(EKEY_CODE::KEY_ESCAPE))
			device->closeDevice();
	}
	device->drop();
	return 0;
}










