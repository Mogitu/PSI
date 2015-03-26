#ifndef PARTICLESETTINGS_H
#define PARTICLESETTINGS_H

#include "irrlicht.h"
#include <QObject>
#include <QWidget>
#include "ui_mainwindow.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;

class ParticleSettings{
    public:
        ParticleSettings(IrrlichtDevice* device);
        ~ParticleSettings();

        //common settings
        stringw imagepath;
        QString type;
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

        //sphere settings
        u32 sphereRadius;
        //box settings
        aabbox3d<f32> boxSize;

        //functions
        void setColorBright(QColor& color);
        void setColorDark(QColor& color);
        void setDirection(float x, float y, float z);
        void createParticle();
        void createEmitter();
        void exportToFile(stringw fileName, Ui_MainWindow *ui);

    private:        
        //vars
        IParticleSystemSceneNode* particleNode;
        IParticleEmitter* particleEmitter;
        IParticleAffector* particleAffector;
        IrrlichtDevice* device;
        ISceneManager* manager;


        //functions
        void init();

};

#endif // PARTICLEMANAGER

