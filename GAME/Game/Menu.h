#ifndef MENU_H
#define MENU_H

#include "irrlicht.h"

using namespace irr;
using namespace gui;

class Menu{
public:
	Menu(IrrlichtDevice *device);
	~Menu();

	void draw();
	void update();
private:
	IrrlichtDevice *device;
	IGUIEnvironment *gui;
	IGUIButton *pauseButton;
	IGUIButton *restartButton;
};
#endif //MENU_H