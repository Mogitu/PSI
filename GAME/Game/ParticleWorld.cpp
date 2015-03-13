#include "ParticleWorld.h"

IVideoDriver* ParticleWorld::driver;
ISceneManager* ParticleWorld::smgr;


void ParticleWorld::setDriver(IVideoDriver* d)
{
	driver = d;
}

void ParticleWorld::setSMGR(ISceneManager* m)
{
	smgr = m;
}

IParticleSystemSceneNode* ParticleWorld::createParticleSystem(vector3df position, vector3df scale, io::path texture, u32 textureLayer, E_MATERIAL_FLAG lightning, bool flagLight, E_MATERIAL_FLAG zwr, bool flagZWR, E_MATERIAL_TYPE eType, bool fadeOut)
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
	ps->setMaterialTexture(textureLayer, driver->getTexture(texture));
	ps->setMaterialType(eType);

	//psList.push_back(ps);

	return ps;
}

void ParticleWorld::createBoxParticle(IParticleSystemSceneNode* ps, aabbox3d<f32> size, vector3df dir, u32 minRate, u32 maxRate, SColor minColor, SColor maxColor, u32 minTime, u32 maxTime, u32 angle, dimension2df minSize, dimension2df maxSize)
{
	IParticleEmitter* em = ps->createBoxEmitter(size, dir, minRate, maxRate, minColor, maxColor, minTime, maxTime, angle, minSize, maxSize);
	ps->setEmitter(em);
	em->drop();
}