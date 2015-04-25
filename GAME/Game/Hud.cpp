#include "Hud.h"


Hud::Hud(IrrlichtDevice *device, Player *player, GameWorld *gameWorld) :device(device), player(player), gameWorld(gameWorld)
{
	gui = device->getGUIEnvironment();
	font = gui->getFont("../Assets/Fonts/myfont.xml");
}

Hud::~Hud()
{

}


void Hud::draw()
{
	//default textcolor, yellow
	SColor textColor(255, 255, 255, 0);
	//player health
	font->draw(L"Health:", rect<s32>(3, 0, 300, 50), textColor);
	stringw playerHealth(player->health);
	font->draw(playerHealth, rect<s32>(70, 0, 300, 50), textColor);
	//score
	stringw playerScore(player->getScore());
	font->draw(L"Score:", rect<s32>(3, 20, 300, 50), textColor);
	font->draw(playerScore, rect<s32>(70, 20, 300, 50), textColor);
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