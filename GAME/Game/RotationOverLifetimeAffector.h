#ifndef __ROTATION_OVER_LIFETIME_AFFECTOR_H_INCLUDED__
#define __ROTATION_OVER_LIFETIME_AFFECTOR_H_INCLUDED__

#include "ParticleAffector.h"
using namespace irr;
using namespace scene;

//! A particle affector which rotates the particle system.
class RotationOverLifetimeAffector : public ParticleAffector
{
public:
	RotationOverLifetimeAffector(core::vector3df rotationPerSecond = core::vector3df());

	void affect(u32 now, SParticle* particlearray, u32 count);



private:

	u32 LastTime;
	core::vector3df RotationPerSecond;
};


#endif

