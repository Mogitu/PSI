#include "StaticModel.h"

StaticModel::StaticModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position) : Model(position)
{
	this->Initialize(smgr, driver, meshName, textureName);
}

StaticModel::StaticModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation) : Model(position, rotation)
{
	this->Initialize(smgr, driver, meshName, textureName);
}

StaticModel::StaticModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale) : Model(position, rotation, scale)
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
		sNode->setPosition(this->getPosition());
		sNode->setRotation(this->getRotation());
		sNode->setScale(this->getScale());

		sNode->setMaterialFlag(EMF_LIGHTING, false);
		sNode->setMaterialTexture(0, driver->getTexture(textureName));
	}
}

StaticModel::~StaticModel()
{
	delete this->sMesh;
	delete this->sNode;
}