#include "ParticleManager.h"
#include <iostream>
#include <string>

ParticleManager::ParticleManager(IrrlichtDevice* dev):device(dev), manager(dev->getSceneManager())
{
    init();
}

ParticleManager::~ParticleManager()
{    
    particleNode->drop();
}

//init the manager and set some default values
void ParticleManager::init()
{
    minStartSize=1;
    maxStartSize=2;

    minRate=100;
    maxRate=200;

    minTime =200;
    maxTime =300;

    sphereRadius =10;
    boxSize.MinEdge=vector3df(-7,0,-7);
    boxSize.MaxEdge = vector3df(7,1,7);

    minColor.set(0,255,255,255);
    maxColor.set(0,255,255,255);
    direction.set(0,0.06,0);
    createParticle();
}

void ParticleManager::setColorBright(QColor& color)
{
   minColor.setRed(color.red());
   minColor.setGreen(color.green());
   minColor.setBlue(color.blue());
}

void ParticleManager::setColorDark(QColor& color)
{
    maxColor.setRed(color.red());
    maxColor.setGreen(color.green());
    maxColor.setBlue(color.blue());
}

void ParticleManager::setDirection(float x, float y, float z)
{
    direction.set(x,y,z);
}

//Creates a full particle effect with the default settings from init()
void ParticleManager::createParticle()
{
    particleNode = device->getSceneManager()->addParticleSystemSceneNode(false);
    particleEmitter = particleNode->createBoxEmitter(
                        boxSize,
                        direction,
                        minRate, maxRate,
                        minColor,
                        maxColor,
                        minTime,maxTime,0,
                        dimension2df(minStartSize,minStartSize),
                        dimension2df(maxStartSize,maxStartSize));

    particleNode->setEmitter(particleEmitter);
    particleEmitter->drop();

    particleAffector = particleNode->createFadeOutParticleAffector();

    particleNode->addAffector(particleAffector);
    particleAffector->drop();

    particleNode->setPosition(vector3df(0,0,0));
    particleNode->setScale(vector3df(0.5,0.5,0.5));
    particleNode->setMaterialFlag(EMF_LIGHTING, false);
    particleNode->setMaterialFlag(EMF_ZWRITE_ENABLE, false);
    particleNode->setMaterialTexture(0, device->getVideoDriver()->getTexture("fire.bmp"));
    particleNode->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
}

//creates and sets a new emitter for the current particlenode.
void ParticleManager::createEmitter()
{
    particleNode->clearParticles();

    std::cout<<type.toStdString()<<std::endl;
    if(type.toStdString()=="Box")
    {
        particleEmitter = particleNode->createBoxEmitter(
                            boxSize,
                            direction,
                            minRate, maxRate,
                            minColor,
                            maxColor,
                            minTime,maxTime,0,
                            dimension2df(minStartSize,minStartSize),
                            dimension2df(maxStartSize,maxStartSize));

    }
    else if(type.toStdString()=="Sphere")
    {
        particleEmitter = particleNode->createSphereEmitter(
                            vector3df(0,0,0),
                            sphereRadius,
                            direction,
                            minRate, maxRate,
                            minColor,
                            maxColor,
                            minTime,maxTime,0,
                            dimension2df(minStartSize,minStartSize),
                            dimension2df(maxStartSize,maxStartSize));
    }
    particleNode->setEmitter(particleEmitter);
}
