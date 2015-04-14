// Copyright (C) 2010-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "ParticleAffector.h"
#include "IAttributes.h"

namespace irr
{
	namespace scene
	{
		ParticleAffector::ParticleAffector()
		{
#ifdef _DEBUG
			setDebugName("ParticleAffector");
#endif
		}


		void  ParticleAffector::affect(u32 now, SParticle *particlearray, u32 count)
		{
		}


		void ParticleAffector::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
		{
		}


		void  ParticleAffector::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
		{
		}


		E_PARTICLE_AFFECTOR_TYPE ParticleAffector::getType() const
		{
			return scene::EPAT_SCALE;
		}
	}
}

