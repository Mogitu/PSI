#ifndef PARTICLE_WORLD_H
#define PARTICLE_WORLD_H

#include <irrlicht.h>

using namespace irr;
using namespace scene;
using namespace core;
using namespace video;

class ParticleWorld
{	
private:
	static list<IParticleSystemSceneNode*> psList;
	static IVideoDriver* driver;
	static ISceneManager* smgr;
public:
	static IParticleSystemSceneNode* createParticleSystem(vector3df position, vector3df scale, io::path texture, u32 textureLayer = 0, E_MATERIAL_FLAG lightning = EMF_LIGHTING, bool flagLight = false, E_MATERIAL_FLAG zwr = EMF_ZWRITE_ENABLE, bool flagZWR = false, E_MATERIAL_TYPE eType = EMT_TRANSPARENT_ADD_COLOR, bool fadeOut = true);
	static void createBoxParticle(IParticleSystemSceneNode* ps, aabbox3d<f32> size, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize);
	static void createBoxParticle(IParticleSystemSceneNode* ps, stringw file, IrrlichtDevice *device);
	static void setDriver(IVideoDriver* d);
	static void setSMGR(ISceneManager* m);
};

#endif

