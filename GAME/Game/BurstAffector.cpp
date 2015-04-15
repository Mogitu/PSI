// Copyright (C) 2010-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "BurstAffector.h"
#include "IAttributes.h"

namespace irr
{
	namespace scene
	{
		BurstAffector::BurstAffector(const const f32& timeBetweenBursts, const const f32& burstTime, const u32& burstAmount) : TimeBetweenBursts(timeBetweenBursts), BurstTime(burstTime), BurstAmount(burstAmount)
		{
#ifdef _DEBUG
			setDebugName("ParticleAffector");
#endif
		}


		void  BurstAffector::affect(u32 now, SParticle *particlearray, u32 count)
		{

			if (LastTime == 0)
			{
				LastTime = now;
				LastBurstTimer = 0;
				return;
			}

			if (!Enabled)return;

			f32 deltaTime = ((f32)(now - LastTime)) / 1000.0;
			LastBurstTimer += deltaTime;
			LastTime = now;
			if (LastBurstTimer > BurstTime)
			{
				ps->em->setMinParticlesPerSecond(0);
				ps->em->setMaxParticlesPerSecond(0);
			}
			if (LastBurstTimer >= TimeBetweenBursts)
			{
				LastBurstTimer = 0;
				ps->em->setMinParticlesPerSecond(BurstAmount);
				ps->em->setMaxParticlesPerSecond(BurstAmount);
			}
		}


		/*void ParticleAffector::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
		{
		}


		void  ParticleAffector::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
		{
		}
		*/

		E_PARTICLE_AFFECTOR_TYPE BurstAffector::getType() const
		{
			return scene::EPAT_SCALE;
		}
	}
}

