#include "AnimatedModel.h"

AnimatedModel::AnimatedModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position) : Model(position)
{
	this->Initialize(smgr, driver, meshName, textureName);
}

AnimatedModel::AnimatedModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation) : Model(position, rotation)
{
	this->Initialize(smgr, driver, meshName, textureName);
}

AnimatedModel::AnimatedModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale) : Model(position, rotation, scale)
{
	this->Initialize(smgr, driver, meshName, textureName);
}

void AnimatedModel::Initialize(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName)
{
	aMesh = smgr->getMesh(meshName);

	if (!aMesh)
		return;

	aNode = smgr->addAnimatedMeshSceneNode(aMesh);

	if (aNode)
	{
		aNode->setPosition(this->getPosition());
		aNode->setRotation(this->getRotation());
		aNode->setScale(this->getScale());

		aNode->setMaterialFlag(EMF_LIGHTING, false);
		aNode->setMD2Animation(scene::EMAT_STAND);
		aNode->setMaterialTexture(0, driver->getTexture(textureName));
	}
}

AnimatedModel::~AnimatedModel()
{
	delete this->aMesh;
	delete this->aNode;
}