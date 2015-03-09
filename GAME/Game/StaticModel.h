#ifndef __STATIC_MODEL_H__
#define __STATIC_MODEL_H__
#include "Model.h"
class StaticModel : public Model
{
private:
	IMesh* sMesh;
	IMeshSceneNode* sNode;
public:
	StaticModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position);
	StaticModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation);
	StaticModel(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName, vector3df position, vector3df rotation, vector3df scale);


	void Initialize(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName);
	~StaticModel();
};
#endif // !__STATIC_MODEL_h__
