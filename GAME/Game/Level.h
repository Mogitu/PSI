#ifndef LEVEL_H
#define LEVEL_H

#include <irrlicht.h>
#include <iostream>
#include <string>

class Level
{
public:
	Level(irr::scene::ISceneManager *smgr,irr::io::path path);	
	~Level();
	irr::scene::ISceneNode *getNamedNode(std::string name);
	irr::core::array<irr::scene::ISceneNode *> getNodes();
private:	
	irr::scene::ISceneManager *smgr;	
	irr::core::array<irr::scene::ISceneNode *> nodes;
};

#endif LEVEL_H