// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "myAffector.h"
#include "IAttributes.h"

namespace irr
{
	namespace scene
	{

		//! constructor
		MyAffector::MyAffector(const core::vector3df& speed, const core::vector3df& pivotPoint)
			: PivotPoint(pivotPoint), Speed(speed), LastTime(0)
		{
#ifdef _DEBUG
			setDebugName("MyAffector");
#endif
		}


		//! Affects an array of particles.
		void MyAffector::affect(u32 now, SParticle* particlearray, u32 count)
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
				PivotPoint = irr::core::vector3df(0,0,0);
				if (Speed.X != 0.0f)
					particlearray[i].pos.rotateYZBy(timeDelta * Speed.X, PivotPoint);

				if (Speed.Y != 0.0f)
					particlearray[i].pos.rotateXZBy(timeDelta * Speed.Y, PivotPoint);

				if (Speed.Z != 0.0f)
					particlearray[i].pos.rotateXYBy(timeDelta * Speed.Z, PivotPoint);
			}
		}

		//! Writes attributes of the object.
		void MyAffector::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const
		{
			out->addVector3d("PivotPoint", PivotPoint);
			out->addVector3d("Speed", Speed);
		}

		//! Reads attributes of the object.
		void MyAffector::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
		{
			PivotPoint = in->getAttributeAsVector3d("PivotPoint");
			Speed = in->getAttributeAsVector3d("Speed");
		}

	} // end namespace scene
} // end namespace irr

