#ifndef PARTICLE_WORLD_H
#define PARTICLE_WORLD_H

#include <irrlicht.h>
#include "Common.h"

using namespace Common;

enum ParticleTag
{
	NONE,
	PLAYER_HIT
};

struct ParticleSystem
{
public:
	IParticleSystemSceneNode* psNode;
	ParticleTag tag;
};

namespace ParticleManager
{
	static void startParticleSystem(ParticleTag tag);
	static void stopParticleSystem(ParticleTag tag);
	static bool isEmitting(ParticleTag tag);
	static void createBoxParticle(IParticleSystemSceneNode* ps, aabbox3d<f32> size, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize);
	static void createSphereParticle(IParticleSystemSceneNode* ps, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize);
	static void addParticleSystemNode(IParticleSystemSceneNode* ps, ParticleTag tag);

	static IParticleSystemSceneNode* createParticleSystem(ParticleTag tag, vector3df position, vector3df scale, io::path texture, u32 textureLayer = 0, E_MATERIAL_FLAG lightning = EMF_LIGHTING, bool flagLight = false, E_MATERIAL_FLAG zwr = EMF_ZWRITE_ENABLE, bool flagZWR = false, E_MATERIAL_TYPE eType = EMT_TRANSPARENT_ADD_COLOR, bool fadeOut = true);
};

//class ParticleWorld
//{	
//private:
//	static list<IParticleSystemSceneNode*> psList;
//	static IVideoDriver* driver;
//	static ISceneManager* smgr;
//public:
//	static IParticleSystemSceneNode* createParticleSystem(vector3df position, vector3df scale, io::path texture, u32 textureLayer = 0, E_MATERIAL_FLAG lightning = EMF_LIGHTING, bool flagLight = false, E_MATERIAL_FLAG zwr = EMF_ZWRITE_ENABLE, bool flagZWR = false, E_MATERIAL_TYPE eType = EMT_TRANSPARENT_ADD_COLOR, bool fadeOut = true);
//	static void createBoxParticle(IParticleSystemSceneNode* ps, aabbox3d<f32> size, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize);
//	static void setDriver(IVideoDriver* d);
//	static void setSMGR(ISceneManager* m);
//};
#endif





