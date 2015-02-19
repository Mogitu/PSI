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
	void Initialize(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName);
	~StaticModel();
};
#endif // !__STATIC_MODEL_h__
