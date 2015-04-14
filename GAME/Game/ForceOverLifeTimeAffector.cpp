// Copyright (C) 2010-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "ForceOverLifeTimeAffector.h"
#include "IAttributes.h"

namespace irr
{
	namespace scene
	{
		ForceOverLifeTimeAffector::ForceOverLifeTimeAffector(const core::vector3df& force) : Force(force)
		{
#ifdef _DEBUG
			setDebugName("ParticleAffector");
#endif
		}


		void  ForceOverLifeTimeAffector::affect(u32 now, SParticle *particlearray, u32 count)
		{
			if (LastTime == 0)
			{
				LastTime = now;
				return;
			}

			if (!Enabled)return;

			f32 deltaTime = ((f32)(now - LastTime)) / 1000.0;
			LastTime = now;
			for (u32 i = 0; i<count; i++)
				particlearray[i].pos += Force*deltaTime;
		}


		/*void ParticleAffector::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
		{
		}


		void  ParticleAffector::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
		{
		}*/


		E_PARTICLE_AFFECTOR_TYPE ForceOverLifeTimeAffector::getType() const
		{
			return scene::EPAT_SCALE;
		}
	}
}

