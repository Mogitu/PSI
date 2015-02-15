#include "ParticleManager.h"



ParticleManager::ParticleManager(IrrlichtDevice* dev):device(dev), manager(dev->getSceneManager())
{
    init();
}

ParticleManager::~ParticleManager()
{
    delete dark;
    delete bright;
    particleNode->drop();
}

void ParticleManager::init()
{
    minScale=1;
    maxScale=2;

    dark = new vector3di(255,255,255);
    bright = new vector3di(255,255,255);
    createParticle();
}

void ParticleManager::setColor(QColor& color)
{
   bright->X = color.red();
   bright->Y = color.green();
   bright->Z = color.blue();
}


void ParticleManager::createParticle()
{
    particleNode = device->getSceneManager()->addParticleSystemSceneNode(false);
    particleEmitter = particleNode->createBoxEmitter(
                        aabbox3d<f32>(-7,0,-7,7,1,7),  // emitter size
                        vector3df(0.0f,0.06f,0.0f),    // initial direction
                        80,100,                              // emit rate
                        SColor(0,dark->X,dark->Y,dark->Z),        // darkest color
                        SColor(0,bright->X,bright->Y,bright->Z),        // brightest color
                        800,2000,20,                         // min and max age, angle
                       //core::dimension2df(10.f,10.f),       // min size
                        dimension2df(minScale,minScale),
                        dimension2df(maxScale, maxScale));      // max size

    particleNode->setEmitter(particleEmitter); // this grabs the emitter
    particleEmitter->drop(); // so we can drop it here without deleting it

    particleAffector = particleNode->createFadeOutParticleAffector();

    particleNode->addAffector(particleAffector); // same goes for the affector
    particleAffector->drop();

    particleNode->setPosition(vector3df(0,0,0));
    particleNode->setScale(vector3df(0.5,0.5,0.5));
    particleNode->setMaterialFlag(EMF_LIGHTING, false);
    particleNode->setMaterialFlag(EMF_ZWRITE_ENABLE, false);
    particleNode->setMaterialTexture(0, device->getVideoDriver()->getTexture("fire.bmp"));
    particleNode->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
}


void ParticleManager::createEmitter()
{
    particleNode->clearParticles();
    particleEmitter = particleNode->createBoxEmitter(
                aabbox3d<f32>(-7,0,-7,7,1,7),  // emitter size
                vector3df(0.0f,0.06f,0.0f),    // initial direction
                80,100,                              // emit rate
                SColor(0,255,255,255),        // darkest color
                SColor(0,bright->X,bright->Y,bright->Z),        // brightest color
                800,2000,20,                         // min and max age, angle
               //core::dimension2df(10.f,10.f),       // min size
                dimension2df(minScale,minScale),
                dimension2df(maxScale, maxScale));      // max size

    particleNode->setEmitter(particleEmitter);
}
