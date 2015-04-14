#ifndef FORCE_OVER_LIFETIME_AFFECTOR_H
#define FORCCE_OVER_LIFETIME_AFFECTOR_H

#include "ParticleAffector.h"
namespace irr
{
	namespace scene
	{
		class ForceOverLifeTimeAffector : public ParticleAffector
		{
		public:
			ForceOverLifeTimeAffector(const core::vector3df& force = core::vector3df(1.0f, 1.0f,1.0f));

			virtual void affect(u32 now, SParticle *particlearray, u32 count);


			//! Get emitter type
			virtual E_PARTICLE_AFFECTOR_TYPE getType() const;

		private:
			vector3df Force;
			u32 LastTime;
		};
	}
}


#endif // PARTICLE_SCALE_AFFECTOR_H

