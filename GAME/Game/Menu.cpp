#include "Menu.h"


Menu::Menu(IrrlichtDevice *device):device(device){
	gui = device->getGUIEnvironment();
};


Menu::~Menu(){};