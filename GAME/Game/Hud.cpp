#include "Hud.h"


Hud::Hud(IrrlichtDevice *device, Player *player, GameWorld *gameWorld, stringc imagePath) :device(device), player(player), gameWorld(gameWorld)
{
	gui = device->getGUIEnvironment();
	driver = device->getVideoDriver();
	image = driver->getTexture(imagePath);
	font = gui->getFont("../Assets/Fonts/myfont.xml");
}

Hud::~Hud()
{

}

void Hud::draw()
{
	//default color
	SColor textColor(255, 255, 255, 255);		
	//draw  hearth image
	driver->draw2DImage(image,position2d<s32>(0,0),rect<s32>(0,0,64,64),0,textColor,true);
	//draw healthbar
	driver->draw2DImage(image, position2d<s32>(64, 0), rect<s32>(0, 64, 128*player->health*0.01, 128), 0, textColor, true);
	//draw weapon inventory
	driver->draw2DImage(image, position2d<s32>(256, 0), rect<s32>(64, 0, 128,64), 0, textColor, true);	
	//draw selection highlight around current weapon
	driver->draw2DImage(image, position2d<s32>(256, 0), rect<s32>(0, 128, 64, 196), 0, textColor, true);
	/*
	//score
	stringw playerScore(player->getScore());
	font->draw(L"Score:", rect<s32>(3, 20, 300, 50), textColor);
	font->draw(playerScore, rect<s32>(70, 20, 300, 50), textColor);
	*/
	//when gameover
	if (player->health <= 0 || !player->isAlive)
	{
		font->draw(L"GAME OVER", rect<s32>(300, 300, 300, 50), textColor);
	}
	if (gameWorld->gameState == GAMESTATE::LEVELCOMPLETE)
	{
		font->draw(L"LEVEL COMPLETE!!!", rect<s32>(300, 300, 300, 50), textColor);
	}	
}

void Hud::moveWeaponSelectionHightlight()
{

}