#ifndef HUD_H
#define HUD_H

#include "irrlicht.h"
#include "HudObject.h"
#include "Player.h"
#include "GameWorld.h"

using namespace irr;
using namespace gui;

class Hud{


public:
	Hud(IrrlichtDevice *device, Player *p, GameWorld *gameWorld);
	~Hud();
	void draw();

private:
	HudObject *healthBar;
	HudObject *backGround;
	HudObject *healthImg;
	HudObject *selectedWeapon;


	list<HudObject*> weapons;
	IrrlichtDevice *device;
	IGUIEnvironment *gui;
	IGUIFont *font;
	Player *player;
	GameWorld *gameWorld;

};


#endif //HUD_H