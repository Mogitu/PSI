#include "irrlicht.h"
#include "Level.h"


Level::Level(irr::scene::ISceneManager *smgr, irr::io::path path) : smgr(smgr)
{
	smgr->loadScene(path);
	smgr->getSceneNodesFromType(irr::scene::ESNT_ANY, nodes); 
}

Level::~Level()
{

}

irr::core::array<irr::scene::ISceneNode *> Level::getNodes()
{
	return nodes;
}


irr::scene::ISceneNode* Level::getNamedNode(std::string name)
{
	irr::scene::ISceneNode *tmp = nullptr;
	for (irr::u32 i = 0; i < nodes.size();i++)
	{
		if (nodes[i]->getName() == name)
		{			
			tmp = nodes[i];
		}
	}
	return tmp;
}
