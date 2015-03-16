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
	f32 minStartSize;
	f32 maxStartSize;	
	f32 duration;
	

private :

	stringw settingsFile; // location of the xml, usually the
	irr::IrrlichtDevice* device;
	
};

#endif