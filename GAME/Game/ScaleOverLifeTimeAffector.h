#ifndef SCALE_OVER_LIFETIME_AFFECTOR_H
#define SCALE_OVER_LIFETIME_AFFECTOR_H

#include "ParticleAffector.h"
namespace irr
{
	namespace scene
	{
		class ScaleOverLifeTimeAffector : public ParticleAffector
		{
		public:
			ScaleOverLifeTimeAffector(const core::dimension2df& scale = core::dimension2df(1.0f, 1.0f));

			virtual void affect(u32 now, SParticle *particlearray, u32 count);


			//! Get emitter type
			virtual E_PARTICLE_AFFECTOR_TYPE getType() const;

		private:
			dimension2df Scale;
			u32 LastTime;
		};
	}
}


#endif // PARTICLE_SCALE_AFFECTOR_H

