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

	//Basic settings
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

	//Affectors etc.

	//Attraction
	bool			attraction;
	vector3df		attraction_point;
	f32				attraction_speed;
	bool			attraction_attract;
	bool			attraction_affectX;
	bool			attraction_affectY;
	bool			attraction_affectZ;

	//Scale
	bool			scaleAF;
	dimension2df	scale_scaleTo;

	//FadeOut
	bool			fade;
	SColor			fade_targetColor;
	u32				fade_timeNeededToFadeOut;

	//Gravity
	bool			gravity;
	vector3df		gravity_gravity;
	u32				gravity_timeForceLost;

	//Rotation
	bool			rotation;
	vector3df		rotation_speed;
	vector3df		rotation_pivotPoint;

private :

	stringw settingsFile; // location of the xml, usually the
	irr::IrrlichtDevice* device;
	
};

#endif