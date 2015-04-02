#include "ParticleManager.h"
#include <vector>

using namespace Common;
using namespace std;

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
			ps->node->setEmitter(ps->em);
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
			ps->node->setEmitter(0);
	}

	bool isEmitting(ParticleTag tag)
	{
		ParticleSystem* ps = findParticleSystem(tag);
		
		return isEmitting(ps);
	}

	bool isEmitting(ParticleSystem* ps)
	{
		if (ps != nullptr)
			return ps->node->getEmitter() != 0;

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

	ParticleSystem* createFullParticleEffect(stringw path, vector3df position, ISceneNode *parent)
	{
		//create an instance that will load/contain all settings from a given path
		ParticleSettings s(Common::device, path);

		//create system and emitter 
		ParticleSystem *ps = createParticleSystem(ParticleManager::ParticleTag::NONE, position, s.scale, s.imagepath);
		
		ps->duration = s.duration;	
		if (parent)
		{
			ps->node->setParent(parent);
		}
		ps->node->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
		ps->node->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
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
			createSphereParticle(ps, vector3df(),
				s.sphereRadius,
				s.direction,
				s.minRate,s.maxRate,
				s.minColor,
				s.maxColor,
				s.minTime,s.maxTime, 0,
				dimension2df(s.minStartSize, s.minStartSize),
				dimension2df(s.maxStartSize, s.maxStartSize));				
		}	
		//Adding the affectors
		std::vector<IParticleAffector*> affectors;//list to make this part less big
		if (s.scaleAF)affectors.push_back(ps->node->createScaleParticleAffector(s.scale_scaleTo));//adding affectors if they are needed
		if (s.attraction)affectors.push_back(ps->node->createAttractionAffector(s.attraction_point, s.attraction_attract, s.attraction_affectX, s.attraction_affectY, s.attraction_affectZ));
		if (s.fade)affectors.push_back(ps->node->createFadeOutParticleAffector(s.fade_targetColor, s.fade_timeNeededToFadeOut));
		if (s.gravity)affectors.push_back(ps->node->createGravityAffector(s.gravity_gravity, s.gravity_timeForceLost));
		if (s.rotation)affectors.push_back(ps->node->createRotationAffector(s.rotation_speed, s.rotation_pivotPoint));
		//FOR TESTING SOME PARTICLE SYSTEMS


		for (std::vector<IParticleAffector*>::iterator affector = affectors.begin(); affector != affectors.end(); ++affector)
		{
			ps->node->addAffector(*affector);//Finally adding them
			(*affector)->drop();//drop is needed
		}
		psList.push_back(ps);
		return ps;
	}

	ParticleSystem* addParticleSystemNode(CParticleSystemSceneNode* n, ParticleTag tag)
	{
		ParticleSystem* pst = new ParticleSystem();
		pst->node = n;
		pst->tag = tag;

		psList.push_back(pst);

		return pst;
	}
	
	ParticleSystem* createParticleSystem(ParticleTag tag, vector3df position, vector3df scale, io::path texture, u32 textureLayer, E_MATERIAL_FLAG lightning, bool flagLight, E_MATERIAL_FLAG zwr, bool flagZWR, E_MATERIAL_TYPE eType, bool fadeOut)
	{
		//CParticleSystemSceneNode* n = (CParticleSystemSceneNode*)smgr->addParticleSystemSceneNode(false);
		CParticleSystemSceneNode* n = new CParticleSystemSceneNode(0, 0, smgr, -1, vector3df(0, 0, 0), vector3df(0, 0, 0), vector3df(1.0f, 1.0f, 1.0f));
		n->drop();
		n->setPosition(position);
		n->setScale(scale);
		n->setMaterialFlag(lightning, flagLight);
		n->setMaterialFlag(zwr, flagZWR);
		n->setMaterialTexture(textureLayer, irrDriver->getTexture(texture));
		n->setMaterialType(eType);
			ParticleSystem* pst = addParticleSystemNode(n, tag);
			return pst;

		//return nullptr;
	}

	void createBoxParticle(ParticleSystem* ps, aabbox3d<f32> size, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize)
	{
		IParticleEmitter* em = ps->node->createBoxEmitter(size, dir, minRate, maxRate, minColor, maxColor, minTime, maxTime, angle, minSize, maxSize);
		ps->node->setEmitter(em);
		ps->em = em;
	}

	void createSphereParticle(ParticleSystem* ps, vector3df center, f32 radius, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize)
	{
		IParticleEmitter* em = ps->node->createSphereEmitter(center, radius, dir, minRate, maxRate, minColor, maxColor, minTime, maxTime, angle, minSize, maxSize);
		ps->node->setEmitter(em);
		ps->em = em;
	}
}