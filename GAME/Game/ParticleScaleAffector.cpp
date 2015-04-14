// Copyright (C) 2010-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "ParticleScaleAffector.h"
#include "IAttributes.h"

namespace irr
{
	namespace scene
	{
		ParticleScaleAffector::ParticleScaleAffector(const core::dimension2df& scale): Scale(scale)
		{
#ifdef _DEBUG
			setDebugName("ParticleAffector");
#endif
		}


		void  ParticleScaleAffector::affect(u32 now, SParticle *particlearray, u32 count)
		{
			for (u32 i = 0; i<count; i++)
			{
				const u32 maxdiff = particlearray[i].endTime - particlearray[i].startTime;
				const u32 curdiff = now - particlearray[i].startTime;
				const f32 newscale = (f32)curdiff / maxdiff;
				particlearray[i].size = particlearray[i].startSize + Scale*newscale;
			}
		}


		/*void ParticleAffector::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
		{
		}


		void  ParticleAffector::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
		{
		}
		*/

		E_PARTICLE_AFFECTOR_TYPE ParticleScaleAffector::getType() const
		{
			return scene::EPAT_SCALE;
		}
	}
}

