#include "StaticModel.h"

StaticModel::StaticModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position) : Model(position)
{
	this->Initialize(smgr, driver, meshName, textureName);
}

void StaticModel::Initialize(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName)
{
	sMesh = smgr->getMesh(meshName);

	if (!sMesh)
		return;

	sNode = smgr->addMeshSceneNode(sMesh);

	if (sNode)
	{
		sNode->setMaterialFlag(EMF_LIGHTING, false);
		sNode->setMaterialTexture(0, driver->getTexture(textureName));
	}
}

StaticModel::~StaticModel()
{
	delete this->sMesh;
	delete this->sNode;
}