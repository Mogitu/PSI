#include "ParticleSettings.h"
#include <iostream>
#include <string>

ParticleSettings::ParticleSettings(IrrlichtDevice* dev):device(dev), manager(dev->getSceneManager())
{
    init();
}

ParticleSettings::~ParticleSettings()
{    
    particleNode->drop();
}

//init the manager and set some default values
void ParticleSettings::init()
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

void ParticleSettings::setColorBright(QColor& color)
{
   minColor.setRed(color.red());
   minColor.setGreen(color.green());
   minColor.setBlue(color.blue());
}

void ParticleSettings::setColorDark(QColor& color)
{
    maxColor.setRed(color.red());
    maxColor.setGreen(color.green());
    maxColor.setBlue(color.blue());
}

void ParticleSettings::setDirection(float x, float y, float z)
{
    direction.set(x,y,z);
}

//Creates a full particle effect with the default settings from init()
void ParticleSettings::createParticle()
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
void ParticleSettings::createEmitter()
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

void ParticleSettings::exportToFile(stringw fileName, Ui_MainWindow *ui){
    //setup te file system and the reader.
    IFileSystem *fs = device->getFileSystem();
    IXMLWriter *xml = fs->createXMLWriter(fileName);

    //need to create the header first
    xml->writeXMLHeader();

    //setup containers with settings
    array<stringw> commonElements;
    array<stringw> commonValues;
    commonElements.push_back(L"imagePath");
    commonElements.push_back(L"scaleX");
    commonElements.push_back(L"scaleY");
    commonElements.push_back(L"scaleZ");
    commonElements.push_back(L"minStartSize");
    commonElements.push_back(L"maxStartSize");
    commonElements.push_back(L"type");
    commonElements.push_back(L"duration");
    commonElements.push_back(L"directionX");
    commonElements.push_back(L"directionY");
    commonElements.push_back(L"directionZ");
    commonElements.push_back(L"minRate");
    commonElements.push_back(L"maxRate");
    commonElements.push_back(L"minTime");
    commonElements.push_back(L"maxTime");
    commonElements.push_back(L"minColorR");
    commonElements.push_back(L"minColorG");
    commonElements.push_back(L"minColorA");
    commonElements.push_back(L"maxColorR");
    commonElements.push_back(L"maxColorG");
    commonElements.push_back(L"maxColorA");


    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(ui->lineMinScale->text().toStdString().c_str());
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");
    commonValues.push_back(L"test");

    //finally write to the file
    xml->writeElement(L"commonSettings",false,commonElements,commonValues);   
    xml->writeLineBreak();

    xml->drop();
}
