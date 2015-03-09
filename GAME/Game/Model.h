#ifndef __MODEL_H__
#define __MODEL_H__

#include <irrlicht.h>

using namespace irr;
using namespace scene;
using namespace core;
using namespace video;

class Model
{
private:
	vector3df position;
	vector3df rotation;
	vector3df scale;
	ISceneNode* node;
public:
	Model(vector3df position);
	Model(vector3df position, vector3df rotation);
	Model(vector3df position, vector3df rotation, vector3df scale);
	vector3df getPosition() { return position; }
	vector3df getRotation() { return rotation; }
	vector3df getScale() { return scale; }
	void addVelocity(vector3df velocity) { position += velocity; }
	virtual void Initialize(ISceneManager* smgr, IVideoDriver* driver, io::path meshName, io::path textureName) = 0;
};

#endif