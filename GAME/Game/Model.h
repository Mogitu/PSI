#ifndef __MODEL_H__
#define __MODEL_H__

#include <irrlicht.h>

using namespace irr;
using namespace scene;
using namespace core;
using namespace video;

class Model
{
public:
	vector3df position;
		
	Model(vector3df position);
	virtual void Initialize(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName) = 0;
};

#endif