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

    //Attraction
    attraction = false;
    attraction_point = vector3df(0,0,0);
    attraction_speed = f32(0);
    attraction_attract = false;
    attraction_affectX = false;
    attraction_affectY = false;
    attraction_affectZ = false;

    //Scale
    scaleAF = false;
    scale_scaleTo.Width = 10.0;
    scale_scaleTo.Height = 10.0;

    //FadeOut
    fade = false;
    fade_targetColor.set(0,255,255,255);
    fade_timeNeededToFadeOut = u32(1000);

    //Gravity
    gravity = false;
    gravity_gravity = vector3df(0,0,0);
    gravity_timeForceLost = u32(1000);

    //Rotation
    rotation = false;
    rotation_speed = vector3df(0,0,0);
    rotation_pivotPoint = vector3df(0,0,0);

    //ring settings
    ringRadius=20;
    ringThickness=20;

    //cylinder settings
    cylinderRadius =20;
    cylinderOutLineOnly =false;

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

void ParticleSettings::setColorFade(QColor& color)
{
    fade_targetColor.setRed(color.red());
    fade_targetColor.setGreen(color.green());
    fade_targetColor.setBlue(color.blue());
}

void ParticleSettings::setDirection(float x, float y, float z)
{
    direction.set(x,y,z);
}

void ParticleSettings::setAttractionPoint(float x, float y, float z)
{
    attraction_point.set(x,y,z);
}

void ParticleSettings::setGravity(float x, float y, float z)
{
    gravity_gravity.set(x,y,z);
}

void ParticleSettings::setRotation(float x, float y, float z)
{
    rotation_pivotPoint.set(x,y,z);
}

void ParticleSettings::setRotationspeed(float x, float y, float z)
{
    rotation_speed.set(x,y,z);
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
    else if(type.toStdString() == "cylinder")
    {
        particleEmitter = particleNode->createCylinderEmitter(vector3df(0,0,0),
                                                              cylinderRadius,vector3df(0,1,0),10,cylinderOutLineOnly,
                                                              direction,                                                                                                                     minRate,maxRate,
                                                              minColor,maxColor,
                                                              minTime,maxTime,0,
                                                              dimension2df(minStartSize,minStartSize),
                                                              dimension2df(maxStartSize,maxStartSize));

    }
    else if(type.toStdString() == "point")
    {
       particleEmitter = particleNode->createPointEmitter(direction,
                                                          minRate,maxRate,
                                                          minColor,maxColor,
                                                          minTime,maxTime,0,
                                                          dimension2df(minStartSize,minStartSize),
                                                          dimension2df(maxStartSize,maxStartSize));
    }else if(type.toStdString() == "ring")
    {
        particleEmitter = particleNode->createRingEmitter(vector3df(0,0,0),
                                                          ringRadius,ringThickness,
                                                          direction,
                                                          minRate, maxRate,
                                                          minColor,maxColor,
                                                          minTime,maxTime,0,
                                                          dimension2df(minStartSize,minStartSize),
                                                          dimension2df(maxStartSize,maxStartSize));
    }
    particleNode->setEmitter(particleEmitter);
}

void ParticleSettings::createAffector()
{
    //Remove all current Affectors
    particleNode->removeAllAffectors();

    //So everything can be easily added
    std::vector<IParticleAffector*> affectors;

    //Set Particleaffectors
    if(attraction == true)
    {
        affectors.push_back(particleNode->createAttractionAffector(attraction_point, attraction_attract, attraction_affectX, attraction_affectY, attraction_affectZ));
    }
    if(fade == true)
    {
        affectors.push_back(particleNode->createFadeOutParticleAffector(fade_targetColor, fade_timeNeededToFadeOut));
    }
    if(gravity == true)
    {
        affectors.push_back(particleNode->createGravityAffector(gravity_gravity, gravity_timeForceLost));
    }
    if(rotation == true)
    {
        affectors.push_back(particleNode->createRotationAffector(rotation_speed, rotation_pivotPoint));
    }
    if(scaleAF == true)
    {
        affectors.push_back(particleNode->createScaleParticleAffector(scale_scaleTo));
    }

    for (std::vector<IParticleAffector*>::iterator affector = affectors.begin(); affector != affectors.end(); ++affector)
    {
        particleNode->addAffector(*affector);//Finally adding them
        (*affector)->drop();//drop is needed
    }

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

    //cylinder settings
    if(ui->comboShape->currentText().toStdString()=="cylinder")
    {
        array<stringw> cylinderElements;
        array<stringw> cylinderValues;
        //the value=1 is currently mandatory as we check in the game framework for this. might get rid of this later.
        cylinderElements.push_back(L"value");
        cylinderValues.push_back(L"1");

        cylinderElements.push_back(L"cylinderRadius");
        cylinderValues.push_back(ui->lineCylinderRadius->text().toStdString().c_str());

        cylinderElements.push_back(L"cylinderOutlineOnly");
        if(ui->checkCylinderOutlineOnly->isChecked())
        {
            cylinderValues.push_back(L"1");
        }else{
            cylinderValues.push_back(L"0");
        }


        xml->writeElement(L"cylinderSettings",false,cylinderElements,cylinderValues);
        xml->writeLineBreak();
    }
    else if(ui->comboShape->currentText().toStdString()=="ring")
    {
        array<stringw> ringElements;
        array<stringw> ringValues;
        //the value=1 is currently mandatory as we check in the game framework for this. might get rid of this later.
        ringElements.push_back(L"value");
        ringValues.push_back(L"1");

        ringElements.push_back(L"ringRadius");
        ringValues.push_back(ui->lineRingRadius->text().toStdString().c_str());

        ringElements.push_back(L"ringThickness");
        ringValues.push_back(ui->lineRingThickness->text().toStdString().c_str());

        xml->writeElement(L"ringSettings",false,ringElements,ringValues);
        xml->writeLineBreak();
    }

    //affector settings
    array<stringw> affectorElements;
    array<stringw> affectorValues;

    affectorElements.push_back(L"value");
    affectorValues.push_back(L"1");

    affectorElements.push_back(L"attraction");
    if(ui->checkAttract->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"attraction_pointX");
    affectorValues.push_back(stringw(attraction_point.X));

    affectorElements.push_back(L"attraction_pointY");
    affectorValues.push_back(stringw(attraction_point.Y));

    affectorElements.push_back(L"attraction_pointZ");
    affectorValues.push_back(stringw(attraction_point.Z));

    affectorElements.push_back(L"attraction_speed");
    affectorValues.push_back(stringw(attraction_speed));

    affectorElements.push_back(L"attraction_attract");
    if(ui->attrAttr->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"attraction_affectX");
    if(ui->attrAttrX->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"attraction_affectY");
    if(ui->attrAttrY->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"attraction_affectZ");
    if(ui->attrAttrZ->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"scale");
    if(ui->checkScale->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"scale_scaleToWidth");
    affectorValues.push_back(stringw(scale_scaleTo.Width));

    affectorElements.push_back(L"scale_scaleToHeight");
    affectorValues.push_back(stringw(scale_scaleTo.Height));

    affectorElements.push_back(L"fade");
    if(ui->checkFade->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"fade_targetColorR");
    affectorValues.push_back(stringw(fade_targetColor.getRed()));

    affectorElements.push_back(L"fade_targetColorG");
    affectorValues.push_back(stringw(fade_targetColor.getGreen()));

    affectorElements.push_back(L"fade_targetColorB");
    affectorValues.push_back(stringw(fade_targetColor.getBlue()));

    affectorElements.push_back(L"fade_targetColorA");
    affectorValues.push_back(L"0");

    affectorElements.push_back(L"fade_timeNeededToFadeOut");
    affectorValues.push_back(stringw(fade_timeNeededToFadeOut));

    affectorElements.push_back(L"gravity");
    if(ui->checkGravity->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"gravity_gravityX");
    affectorValues.push_back(stringw(gravity_gravity.X));

    affectorElements.push_back(L"gravity_gravityY");
    affectorValues.push_back(stringw(gravity_gravity.Y));

    affectorElements.push_back(L"gravity_gravityZ");
    affectorValues.push_back(stringw(gravity_gravity.Z));

    affectorElements.push_back(L"gravity_timeForceLost");
    affectorValues.push_back(stringw(gravity_timeForceLost));

    affectorElements.push_back(L"rotation");
    if(ui->checkRotation->isChecked() == true)
    {
        affectorValues.push_back(L"1");
    } else
    {
        affectorValues.push_back(L"0");
    }

    affectorElements.push_back(L"rotation_speedX");
    affectorValues.push_back(stringw(rotation_speed.X));

    affectorElements.push_back(L"rotation_speedY");
    affectorValues.push_back(stringw(rotation_speed.Y));

    affectorElements.push_back(L"rotation_speedZ");
    affectorValues.push_back(stringw(rotation_speed.Z));

    affectorElements.push_back(L"rotation_pivotPointX");
    affectorValues.push_back(stringw(rotation_pivotPoint.X));

    affectorElements.push_back(L"rotation_pivotPointY");
    affectorValues.push_back(stringw(rotation_pivotPoint.Y));

    affectorElements.push_back(L"rotation_pivotPointZ");
    affectorValues.push_back(stringw(rotation_pivotPoint.Z));

    xml->writeElement(L"AffectorSettings",false,affectorElements,affectorValues);
    xml->writeLineBreak();


    //Need to drop, if we dont the xml wont be written at all.
    xml->drop();
}

void ParticleSettings::loadTexture(QString path)
{
    particleNode->setMaterialTexture(0, device->getVideoDriver()->getTexture(qPrintable(path)));
}

IParticleSystemSceneNode *ParticleSettings::getParticleNode(){
    return particleNode;
}
