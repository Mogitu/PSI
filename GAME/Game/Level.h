#include <irrlicht.h>

#include <iostream>
#include <string>


class Level
{
public:
	Level(irr::scene::ISceneManager *smgr, irr::scene::ISceneNode *node,irr::io::path path);	
	~Level();
	irr::scene::ISceneNode* getNamedNode(std::string name);
	void initialise();	
	void createCollision(irr::scene::ISceneNode *n);
private:	
	irr::scene::ISceneManager *smgr;
	irr::scene::ISceneNode *node;
	irr::core::array<irr::scene::ISceneNode *> nodes;
	irr::scene::IMetaTriangleSelector *meta;

};