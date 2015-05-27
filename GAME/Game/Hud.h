#ifndef HUD_H
#define HUD_H

#include "irrlicht.h"
#include "GameWorld.h"
#include "Elementals.h"

using namespace irr;
using namespace gui;

class Player; //defining player; Forward declaring because we can't include each others headers

class Hud
{
public:
	Hud(IrrlichtDevice *device, Player *p, GameWorld *gameWorld, stringc imagePath);
	~Hud();
	void draw();
	void moveWeaponSelectionHightlight(ElementalType eType);
	void setHasWeapon(ElementalType eType);
private:
	ITexture *image;
	ITexture *gameWinImg;
	ITexture *gameOverImg;
	IVideoDriver *driver;	
	IrrlichtDevice *device;
	IGUIEnvironment *gui;
	IGUIFont *font;
	Player *player;
	GameWorld *gameWorld;
	
	bool hasFireWeapon;
	bool hasIceWeapon;
	bool hasWindWeapon;
	bool hasEarthWeapon;

	const u32 xFire = 256;
	const u32 xIce = 356;
	const u32 xWind = 456;
	const u32 xEarth = 556;

	u32 xSelectionHighlight = 256;
};


#endif //HUD_H