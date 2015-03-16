#include "ParticleManager.h"

using namespace Common;

namespace ParticleManager
{
	namespace
	{
		static list<ParticleSystem*> psList;
	}

	void startParticleSystem(ParticleTag tag, u32 duration)
	{
		ParticleSystem* ps = findParticleSystem(tag);

		if (!isEmitting(ps))
		{
			ps->psNode->setEmitter(ps->em);
			ps->duration = duration;
			ps->elaspedTimer = 0;
		}
	}

	void stopParticleSystem(ParticleTag tag)
	{
		ParticleSystem* ps = findParticleSystem(tag);
		stopParticleSystem(ps);
	}

	void stopParticleSystem(ParticleSystem* ps)
	{
		if (isEmitting(ps))
			ps->psNode->setEmitter(0);
	}

	bool isEmitting(ParticleTag tag)
	{
		ParticleSystem* ps = findParticleSystem(tag);
		
		return isEmitting(ps);
	}

	bool isEmitting(ParticleSystem* ps)
	{
		if (ps != nullptr)
			return ps->psNode->getEmitter() != 0;

		return false;

	}

	void update(u32 frameDeltaTime)
	{
		for (list<ParticleSystem*>::Iterator iterator = psList.begin(); iterator != psList.end(); ++iterator)
		{
			ParticleSystem* pst = *iterator;
			if (pst->duration != -1)
			{
				if (pst->elaspedTimer < pst->duration)
					pst->elaspedTimer += frameDeltaTime;
				else
					stopParticleSystem(pst);
			}
			
		}
	}

	ParticleSystem* findParticleSystem(ParticleTag tag)
	{
		for (list<ParticleSystem*>::Iterator iterator = psList.begin(); iterator != psList.end(); ++iterator)
		{
			ParticleSystem* pst = *iterator;

			if (pst->tag == tag)
				return pst;
		}

		return nullptr;
	}

	void createFullParticleEffect(stringw path, vector3df position)
	{
		//create an instance that will load/contain all settings from a given path
		ParticleSettings s(Common::device, path);

		//create system and emitter 
		ParticleSystem *ps = createParticleSystem(ParticleManager::ParticleTag::NONE, position, vector3df(2, 2, 2), s.imagepath);
		ps->duration = s.duration;	
		//load an emitter type depending on the settings file
		if (s.type=="box")
		{
			createBoxParticle(ps,
				s.boxSize,
				s.direction,
				s.minRate, s.maxRate,
				s.minColor,
				s.maxColor,
				s.minTime,s.maxTime, 0,
				dimension2df(s.minStartSize, s.minStartSize),
				dimension2df(s.maxStartSize, s.maxStartSize));			
		}
		else if (s.type=="sphere")
		{
			createSphereParticle(ps, position,
				s.sphereRadius,
				s.direction,
				s.minRate,s.maxRate,
				s.minColor,
				s.maxColor,
				s.minTime,s.maxTime, 0,
				dimension2df(s.minStartSize, s.minStartSize),
				dimension2df(s.maxStartSize, s.maxStartSize));				
		}		
		psList.push_back(ps);
	}

	ParticleSystem* addParticleSystemNode(IParticleSystemSceneNode* ps, ParticleTag tag)
	{
		ParticleSystem* pst = new ParticleSystem();
		pst->psNode = ps;
		pst->tag = tag;

		psList.push_back(pst);

		return pst;
	}
	
	ParticleSystem* createParticleSystem(ParticleTag tag, vector3df position, vector3df scale, io::path texture, u32 textureLayer, E_MATERIAL_FLAG lightning, bool flagLight, E_MATERIAL_FLAG zwr, bool flagZWR, E_MATERIAL_TYPE eType, bool fadeOut)
	{
		IParticleSystemSceneNode* ps = smgr->addParticleSystemSceneNode(false);
		
			if (fadeOut)
			{
				IParticleAffector* paf = ps->createFadeOutParticleAffector();
				ps->addAffector(paf);
				paf->drop();
			}
		
			ps->setPosition(position);
			ps->setScale(scale);
			ps->setMaterialFlag(lightning, flagLight);
			ps->setMaterialFlag(zwr, flagZWR);
			ps->setMaterialTexture(textureLayer, irrDriver->getTexture(texture));
			ps->setMaterialType(eType);
		
			ParticleSystem* pst = addParticleSystemNode(ps, tag);
		
			return pst;

		//return nullptr;
	}

	void createBoxParticle(ParticleSystem* ps, aabbox3d<f32> size, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize)
	{
		IParticleEmitter* em = ps->psNode->createBoxEmitter(size, dir, minRate, maxRate, minColor, maxColor, minTime, maxTime, angle, minSize, maxSize);
		ps->psNode->setEmitter(em);
		ps->em = em;
	}

	void createSphereParticle(ParticleSystem* ps, vector3df center, f32 radius, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize)
	{
		IParticleEmitter* em = ps->psNode->createSphereEmitter(center, radius, dir, minRate, maxRate, minColor, maxColor, minTime, maxTime, angle, minSize, maxSize);
		ps->psNode->setEmitter(em);
		ps->em = em;
	}
}