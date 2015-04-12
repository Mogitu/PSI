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
    //Set some default values.
    minStartSize=1;
    maxStartSize=2;

    minRate=100;
    maxRate=200;

    minTime =200;
    maxTime =300;

    sphereCenter = vector3df(0, 0, 0);
    sphereRadius = 10;
    boxSize.MinEdge=vector3df(-7, 0, -7);
    boxSize.MaxEdge = vector3df(7, 1, 7);

    minColor.set(0, 255, 255, 255);
    maxColor.set(0, 255, 255, 255);
    direction.set(0, 0.06, 0);

    imagepath= "";
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
    particleNode->setMaterialTexture(0, device->getVideoDriver()->getTexture(imagepath));
    particleNode->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
}

//creates and sets a new emitter for the current particlenode.
void ParticleSettings::createEmitter()
{
    //Remove all current settings from the displayed particle
    particleNode->clearParticles();

    //create emitter based on selection
    if(type.toStdString() == "box")
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
    else if(type.toStdString() == "sphere")
    {
        particleEmitter = particleNode->createSphereEmitter(
                            sphereCenter,
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

    //setup containers with settings, for each extra option we create we should make a new container
    //like an sphere options container, a box options container etc.
    array<stringw> commonElements;
    array<stringw> commonValues;

    //now pushback all elements to write and pair them with values.
    commonElements.push_back(L"imagePath");
    commonValues.push_back(imagepath);

    commonElements.push_back(L"scaleX");
    commonValues.push_back(L"1");

    commonElements.push_back(L"scaleY");
    commonValues.push_back(L"1");

    commonElements.push_back(L"scaleZ");
    commonValues.push_back(L"1");

    commonElements.push_back(L"minStartSize");
    commonValues.push_back(ui->lineMinScale->text().toStdString().c_str());

    commonElements.push_back(L"maxStartSize");
    commonValues.push_back(ui->lineMaxScale->text().toStdString().c_str());

    commonElements.push_back(L"type");
    commonValues.push_back(ui->comboShape->currentText().toStdString().c_str());

    commonElements.push_back(L"duration");
    commonValues.push_back(ui->lineDuration->text().toStdString().c_str());

    commonElements.push_back(L"directionX");
    commonValues.push_back(ui->dirX->text().toStdString().c_str());

    commonElements.push_back(L"directionY");
    commonValues.push_back(ui->dirY->text().toStdString().c_str());

    commonElements.push_back(L"directionZ");
    commonValues.push_back(ui->dirZ->text().toStdString().c_str());

    commonElements.push_back(L"minRate");
    commonValues.push_back(ui->lineMinRate->text().toStdString().c_str());

    commonElements.push_back(L"maxRate");
    commonValues.push_back(ui->lineMaxRate->text().toStdString().c_str());

    commonElements.push_back(L"minTime");
    commonValues.push_back(ui->lineMinTime->text().toStdString().c_str());

    commonElements.push_back(L"maxTime");
    commonValues.push_back(ui->lineMaxTime->text().toStdString().c_str());

    commonElements.push_back(L"minColorR");
    commonValues.push_back(stringw(minColor.getRed()));

    commonElements.push_back(L"minColorG");
    commonValues.push_back(stringw(minColor.getGreen()));

    commonElements.push_back(L"minColorB");
    commonValues.push_back(stringw(minColor.getBlue()));

    commonElements.push_back(L"maxColorR");
    commonValues.push_back(stringw(maxColor.getRed()));

    commonElements.push_back(L"maxColorG");
    commonValues.push_back(stringw(maxColor.getGreen()));

    commonElements.push_back(L"maxColorB");
    commonValues.push_back(stringw(maxColor.getBlue()));

    //finally write to the file, again we should use writelement for each option we have and pass the proper containers in.
    xml->writeElement(L"commonSettings",false,commonElements,commonValues);   
    xml->writeLineBreak();

    //setup box container settings
    if(ui->comboShape->currentText().toStdString()=="box")
    {
        array<stringw> boxElements;
        array<stringw> boxValues;
        //the value=1 is currently mandatory as we check in the game framework for this. might get rid of this later.
        boxElements.push_back(L"value");
        boxValues.push_back(L"1");

        boxElements.push_back(L"minX");
        boxValues.push_back(ui->lineMinBoxX->text().toStdString().c_str());

        boxElements.push_back(L"minY");
        boxValues.push_back(ui->lineMinBoxY->text().toStdString().c_str());

        boxElements.push_back(L"minZ");
        boxValues.push_back(ui->lineMinBoxZ->text().toStdString().c_str());

        boxElements.push_back(L"maxX");
        boxValues.push_back(ui->lineMaxBoxX->text().toStdString().c_str());

        boxElements.push_back(L"maxY");
        boxValues.push_back(ui->lineMaxBoxY->text().toStdString().c_str());

        boxElements.push_back(L"maxZ");
        boxValues.push_back(ui->lineMaxBoxZ->text().toStdString().c_str());

        xml->writeElement(L"boxSettings",false,boxElements,boxValues);
        xml->writeLineBreak();
    }

    //sphere settings
    if(ui->comboShape->currentText().toStdString()=="sphere")
    {
        array<stringw> sphereElements;
        array<stringw> sphereValues;
        //the value=1 is currently mandatory as we check in the game framework for this. might get rid of this later.
        sphereElements.push_back(L"value");
        sphereValues.push_back(L"1");

        sphereElements.push_back(L"radius");
        sphereValues.push_back(ui->lineSpereRadius->text().toStdString().c_str());

        xml->writeElement(L"sphereSettings",false,sphereElements,sphereValues);
        xml->writeLineBreak();
    }

    //Need to drop, if we dont the xml wont be written at all.
    xml->drop();
}

void ParticleSettings::loadTexture(QString path)
{
    particleNode->setMaterialTexture(0, device->getVideoDriver()->getTexture(qPrintable(path)));
}
