#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#include <irrlicht.h>
#include "Common.h"
#include "ParticleSettings.h"

namespace ParticleManager
{
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
		IParticleEmitter* em;
		u32 elaspedTimer;
		u32 duration;
	};
	
	//-1 for an infinite duration
	void startParticleSystem(ParticleTag tag, u32 duration = -1);
	void stopParticleSystem(ParticleTag tag);
	void stopParticleSystem(ParticleSystem* ps);
	bool isEmitting(ParticleTag tag);
	bool isEmitting(ParticleSystem* ps);
	void update(u32 deltaframetime);
	ParticleSystem* findParticleSystem(ParticleTag tag);
	void removeParticleSystem(ParticleTag tag);
	ParticleSystem* createFullParticleEffect(stringw path, vector3df position, ISceneNode *node=0);
	ParticleSystem* addParticleSystemNode(IParticleSystemSceneNode* ps, ParticleTag tag);
	ParticleSystem* createParticleSystem(ParticleTag tag, vector3df position, vector3df scale, io::path texture, u32 textureLayer = 0, E_MATERIAL_FLAG lightning = EMF_LIGHTING, bool flagLight = false, E_MATERIAL_FLAG zwr = EMF_ZWRITE_ENABLE, bool flagZWR = false, E_MATERIAL_TYPE eType = EMT_TRANSPARENT_ADD_COLOR, bool fadeOut = true);
	void createBoxParticle(ParticleSystem* ps, aabbox3d<f32> size, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize);
	void createSphereParticle(ParticleSystem* ps, vector3df center, f32 radius, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize);
};
#endif





