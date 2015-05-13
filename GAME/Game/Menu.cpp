#include "Menu.h"


Menu::Menu(IrrlichtDevice *device, stringc imagePath):device(device){
	gui = device->getGUIEnvironment();
	driver = device->getVideoDriver();
	image = driver->getTexture(imagePath);
};


Menu::~Menu(){};

void Menu::draw()
{
	SColor white(255, 255, 255, 255);
	driver->draw2DImage(image, position2d<s32>(220, 170));
}