#ifndef __PARTICLE_AFFECTOR_H_INCLUDED__
#define __PARTICLE_AFFECTOR_H_INCLUDED__

#include "ParticleManager.h"
#include "IParticleAffector.h"
using namespace irr;
using namespace scene;
using namespace ParticleManager;

//! A particle affector which rotates the particle system.
class ParticleAffector : public IParticleAffector
{
public:
	ParticleAffector();

	virtual void affect(u32 now, SParticle* particlearray, u32 count);

	//The ParticleSystem this affector will have effect on
	ParticleSystem* ps;
	//! Get emitter type
	virtual E_PARTICLE_AFFECTOR_TYPE getType() const;

private:
	u32 LastTime;
};


#endif // __PARTICLE_AFFECTOR_H_INCLUDED__

