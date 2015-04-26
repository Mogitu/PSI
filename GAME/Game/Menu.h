#ifndef MENU_H
#define MENU_H

#include "irrlicht.h"

using namespace irr;
using namespace gui;
using namespace video;
using namespace core;

class Menu{
public:
	Menu(IrrlichtDevice *device, stringc imagePath);
	~Menu();

	void draw();
	void update();
private:
	IrrlichtDevice *device;
	IGUIEnvironment *gui;
	IVideoDriver *driver;
	ITexture *image;
	IGUIButton *pauseButton;
	IGUIButton *restartButton;
};
#endif //MENU_H