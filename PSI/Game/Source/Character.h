#ifndef CHARACTER_H
#define CHARACTER_H

#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Character
{
public:
	Character(IrrlichtDevice* device);

private:
	IrrlichtDevice* device;
	IAnimatedMesh* mesh;
	IAnimatedMeshSceneNode* node;


};

#endif CHARACTER_H