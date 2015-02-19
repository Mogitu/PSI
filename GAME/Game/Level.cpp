#include "irrlicht.h"
#include "Level.h"



Level::Level(irr::scene::ISceneManager *smgr, irr::scene::ISceneNode *node, irr::io::path path) : smgr(smgr), node(node)
{
	smgr->loadScene(path);
	smgr->getSceneNodesFromType(irr::scene::ESNT_ANY, nodes); 
	initialise();
	createCollision(node);
}

Level::~Level()
{

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

void Level::initialise()
{	
	meta = smgr->createMetaTriangleSelector();	
	for (irr::u32 i = 0; i < nodes.size(); ++i)
	{
		irr::scene::ISceneNode * node = nodes[i];
		irr::scene::ITriangleSelector * selector = 0;
		
		switch (node->getType())
		{
			case irr::scene::ESNT_CUBE:
			case irr::scene::ESNT_ANIMATED_MESH:			
				//selector = smgr->createTriangleSelectorFromBoundingBox(node);
				break;
			case irr::scene::ESNT_MESH:
			case irr::scene::ESNT_SPHERE: 
				selector = smgr->createTriangleSelector(((irr::scene::IMeshSceneNode*)node)->getMesh(), node);
				break;

			case irr::scene::ESNT_TERRAIN:
				selector = smgr->createTerrainTriangleSelector((irr::scene::ITerrainSceneNode*)node);
				break;

			case irr::scene::ESNT_OCTREE:
				selector = smgr->createOctreeTriangleSelector(((irr::scene::IMeshSceneNode*)node)->getMesh(), node);
				break;
			default:			
				break;
		}

		if (selector)
		{			
			meta->addTriangleSelector(selector);			
			selector->drop();
		}
	}			
}

void Level::createCollision(irr::scene::ISceneNode *n)
{
	irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
		meta, n, irr::core::vector3df(5, 5, 5),
		irr::core::vector3df(0, -0.05, 0));
	meta->drop();
	n->addAnimator(anim);
	anim->drop();
}