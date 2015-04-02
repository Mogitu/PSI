// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "RotationOverLifetimeAffector.h"
#include "IAttributes.h"

//! constructor
RotationOverLifetimeAffector::ParticleAffector(core::vector3df rotationPerSecond)
{
#ifdef _DEBUG
	setDebugName("RotationOverLifetimeAffector");
#endif
}


//! Affects an array of particles.
void RotationOverLifetimeAffector::affect(u32 now, SParticle* particlearray, u32 count)
{
	if (LastTime == 0)
	{
		LastTime = now;
		return;
	}

	f32 timeDelta = (now - LastTime) / 1000.0f;
	LastTime = now;

	if (!Enabled)
		return;


	for (u32 i = 0; i<count; ++i)
	{


		if (Speed.X != 0.0f)
			particlearray[i].pos.rotateYZBy(timeDelta * Speed.X, PivotPoint);

		if (Speed.Y != 0.0f)
			particlearray[i].pos.rotateXZBy(timeDelta * Speed.Y, PivotPoint);

		if (Speed.Z != 0.0f)
			particlearray[i].pos.rotateXYBy(timeDelta * Speed.Z, PivotPoint);
	}
}


