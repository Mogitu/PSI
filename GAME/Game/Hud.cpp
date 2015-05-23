#include "Hud.h"
#include "Elementals.h"
#include "Player.h"


Hud::Hud(IrrlichtDevice *device, Player *player, GameWorld *gameWorld, stringc imagePath) :device(device), player(player), gameWorld(gameWorld)
{
	gui = device->getGUIEnvironment();
	driver = device->getVideoDriver();
	image = driver->getTexture(imagePath);
	gameOverImg = driver->getTexture("../Assets/textures/gameover.png");
	gameWinImg = driver->getTexture("../Assets/textures/winner.jpg");
	font = gui->getFont("../Assets/Fonts/myfont.xml");
	player->attachHUD(this);
}

Hud::~Hud()
{

}

void Hud::draw()
{
	//default color
	SColor white(255, 255, 255, 255);		
	SColor green(255,34,255,0);
	//draw  hearth image
	driver->draw2DImage(image,position2d<s32>(0,0),rect<s32>(0,0,64,64),0,white,true);
	//draw healthbar
	driver->draw2DImage(image, position2d<s32>(64, 0), rect<s32>(0, 64, 128, 128), 0, white, true);
	driver->draw2DImage(image, position2d<s32>(64, 0), rect<s32>(0, 64, 128 * player->health*0.01, 128), 0, green, true);
	//draw weapons inventory
	if (!hasFireWeapon)
		driver->draw2DImage(image, position2d<s32>(256, 0), rect<s32>(64, 0, 128, 64), 0, white, true);
	else
		driver->draw2DImage(image, position2d<s32>(256, 0), rect<s32>(128, 0, 192, 64), 0, white, true);
	
	if (!hasIceWeapon)
		driver->draw2DImage(image, position2d<s32>(356, 0), rect<s32>(64, 0, 128, 64), 0, white, true);
	else
		driver->draw2DImage(image, position2d<s32>(356, 0), rect<s32>(192, 0, 256, 64), 0, white, true);
	
	if (!hasWindWeapon)
		driver->draw2DImage(image, position2d<s32>(456, 0), rect<s32>(64, 0, 128, 64), 0, white, true);
	else
		driver->draw2DImage(image, position2d<s32>(456, 0), rect<s32>(257, 0, 320, 64), 0, white, true); //The three element items are not well aligned in the image file (did a +1 on the start pos of Wind)

	//draw selection highlight around current weapon
	driver->draw2DImage(image, position2d<s32>(xSelectionHighlight, 0), rect<s32>(0, 128, 64, 196), 0, white, true);
	
	/*
	//score
	stringw playerScore(player->getScore());
	font->draw(L"Score:", rect<s32>(3, 20, 300, 50), textColor);
	font->draw(playerScore, rect<s32>(70, 20, 300, 50), textColor);
	*/
	//when gameover
	if (player->health <= 0 || !player->isAlive)
	{
		//font->draw(L"GAME OVER", rect<s32>(300, 300, 300, 50), white);
		driver->draw2DImage(gameOverImg, position2d<s32>(150, 150), rect<s32>(0, 0, 515, 200), 0, white, true);
	}
	if (gameWorld->gameState == GAMESTATE::LEVELCOMPLETE)
	{
		driver->draw2DImage(gameWinImg, position2d<s32>(150, 150), rect<s32>(0, 0, 400, 323), 0, white, true);
		//font->draw(L"LEVEL COMPLETE!!!", rect<s32>(300, 300, 300, 50), white);
	}	
}

void Hud::moveWeaponSelectionHightlight(ElementalType eType)
{
	switch (eType)
	{
	case Fire:
		xSelectionHighlight = xFire;
		break;
	case Ice:
		xSelectionHighlight = xIce;
		break;
	case Wind:
		xSelectionHighlight = xWind;
		break;
	}	
}

void Hud::setHasWeapon(ElementalType eType)
{
	switch (eType)
	{
	case Fire:
		hasFireWeapon = true;
		break;
	case Ice:
		hasIceWeapon = true;
		break;
	case Wind:
		hasWindWeapon = true;
		break;
	}
}