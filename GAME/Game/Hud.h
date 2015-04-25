#ifndef HUD_H
#define HUD_H

#include "irrlicht.h"
#include "Player.h"
#include "GameWorld.h"

using namespace irr;
using namespace gui;

class Hud{


public:
	Hud(IrrlichtDevice *device, Player *p, GameWorld *gameWorld, stringc imagePath);
	~Hud();
	void draw();	
private:
	ITexture *image;
	IVideoDriver *driver;	
	IrrlichtDevice *device;
	IGUIEnvironment *gui;
	IGUIFont *font;
	Player *player;
	GameWorld *gameWorld;
	void moveWeaponSelectionHightlight();

};


#endif //HUD_H