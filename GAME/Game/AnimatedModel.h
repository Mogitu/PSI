#ifndef __ANIMATED_MODEL_H__
#define __ANIMATED_MODEL_H__

#include "Model.h"

class AnimatedModel : public Model
{
private:
	IAnimatedMeshSceneNode* aNode;
	IAnimatedMesh* aMesh;
public:
	AnimatedModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position);
	AnimatedModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation);
	AnimatedModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale);
	void Initialize(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName);
	void UpdatePos() { aNode->setPosition(this->getPosition()); }
	~AnimatedModel();
};

#endif