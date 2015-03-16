#ifndef PARTICLE_SETTINGS_H
#define PARTICLE_SETTINGS_H

#include <irrlicht.h>


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;


class ParticleSettings
{
public:
	ParticleSettings(IrrlichtDevice *device, stringw file);
	~ParticleSettings();

	stringw imagepath;
	stringc type;
	f32 minStartSize;
	f32 maxStartSize;	
	f32 duration;
	vector3df direction;
	vector3df scale;
	u32 minRate;
	u32 maxRate;
	f32 minTime;
	f32 maxTime;
	SColor minColor;
	SColor maxColor;

	u32 sphereRadius;

	aabbox3d<f32> boxSize;

private :

	stringw settingsFile; // location of the xml, usually the
	irr::IrrlichtDevice* device;
	
};

#endif