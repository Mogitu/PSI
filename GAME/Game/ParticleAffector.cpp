#include "ParticleAffector.h"
#include "IAttributes.h"


//! constructor
ParticleAffector::ParticleAffector()
{
#ifdef _DEBUG
	setDebugName("ParticleAffector");
#endif
}


//! Affects an array of particles.
void ParticleAffector::affect(u32 now, SParticle* particlearray, u32 count)
{
	//Basic stuff of an affector
	if (LastTime == 0)
	{
		LastTime = now;
		return;
	}
	
	f32 timeDelta = (now - LastTime) / 1000.0f;
	LastTime = now;

	if (!Enabled)
		return;
	//example to rotate the particles around a point
	for (u32 i = 0; i<count; ++i)
	{

			//particlearray[i].pos.rotateYZBy(timeDelta * 15, vector3df(1,1,1));
			particlearray[i].size.Width += timeDelta * 5;
			particlearray[i].size.Height += timeDelta * 5;
			/*particlearray[i].pos.rotateXZBy(timeDelta * 15, PivotPoint);

			particlearray[i].pos.rotateXYBy(timeDelta * 15, PivotPoint);*/
	}

}

E_PARTICLE_AFFECTOR_TYPE ParticleAffector::getType() const
{
	return scene::EPAT_SCALE;
}

