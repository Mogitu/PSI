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
        IParticleSystemSceneNode *getParticleNode();
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
        bool isSolid;

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

        //sphere settings
        vector3df sphereCenter;
        u32 sphereRadius;
        //box settings
        aabbox3d<f32> boxSize;
        //point settings

        //Ring settings
        u32 ringRadius;
        u32 ringThickness;

        //cylinder settings
        u32 cylinderRadius;
        bool cylinderOutLineOnly;

        //functions
        void setColorBright(QColor& color);
        void setColorDark(QColor& color);
        void setColorFade(QColor& color);
        void setDirection(float x, float y, float z);
        void setAttractionPoint(float x, float y, float z);
        void setGravity(float x, float y, float z);
        void setRotation(float x, float y, float z);
        void setRotationspeed(float x, float y, float z);
        void createParticle();
        void createEmitter();
        void createAffector();
        void exportToFile(stringw fileName, Ui_MainWindow *ui);
        void loadTexture(QString path);

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

