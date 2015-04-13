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
	//gets a node by name from the nodes array
	irr::scene::ISceneNode *getNamedNode(std::string name);
	//Get all nodes
	irr::core::array<irr::scene::ISceneNode *> getNodes();
private:	
	irr::scene::ISceneManager *smgr;	
	//contains all nodes in the loaded scene
	irr::core::array<irr::scene::ISceneNode *> nodes;
};

#endif LEVEL_H