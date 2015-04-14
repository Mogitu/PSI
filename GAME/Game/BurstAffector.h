#ifndef BURST_AFFECTOR_H
#define BURST_AFFECTOR_H

#include "ParticleAffector.h"
namespace irr
{
	namespace scene
	{
		class BurstAffector : public ParticleAffector
		{
		public:
			BurstAffector(const f32& timeBetweenBursts = 0.25, const f32& burstTime = 0.05, const u32& burstAmount = 25);

			virtual void affect(u32 now, SParticle *particlearray, u32 count);


			//! Get emitter type
			virtual E_PARTICLE_AFFECTOR_TYPE getType() const;

		private:
			f32 TimeBetweenBursts;
			f32 BurstTime;
			u32 BurstAmount;
			u32 LastTime;
			f32 LastBurstTimer;
		};
	}
}


#endif // PARTICLE_SCALE_AFFECTOR_H

