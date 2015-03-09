#include "Character.h"

Character::Character(IrrlichtDevice* dev) 
{	
	device = dev;
	mesh = device->getSceneManager()->getMesh("../Assets/sydney.md2");
	node = device->getSceneManager()->addAnimatedMeshSceneNode(mesh);

	node->setMaterialFlag(EMF_LIGHTING, false);
	node->setMD2Animation(scene::EMAT_STAND);
	node->setMaterialTexture(0, device->getVideoDriver()->getTexture("../Assets/sydney.bmp"));
}

