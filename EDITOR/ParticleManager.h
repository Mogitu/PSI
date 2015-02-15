#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

#include "irrlicht.h"
#include <QObject>
#include <QWidget>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class ParticleManager{
    public:
        ParticleManager(IrrlichtDevice* device);
        ~ParticleManager();

        //vars
        vector3di dark;
        vector3di bright;

        float minScale;
        float maxScale;        

        //functions
        void setColorBright(QColor& color);
        void setColorDark(QColor& color);
        void setDirection(float x, float y, float z);
        void createParticle();
        void createEmitter();

    private:        
        //vars
        IParticleSystemSceneNode* particleNode;
        IParticleEmitter* particleEmitter;
        IParticleAffector* particleAffector;
        IrrlichtDevice* device;
        ISceneManager* manager;
        vector3df direction;

        //functions
        void init();

};

#endif // PARTICLEMANAGER

