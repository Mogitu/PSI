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

        void createParticle();
        void createEmitter();       

        vector3di* dark;
        vector3di* bright;

        float minScale;
        float maxScale;

        void setColor(QColor& color);

    private:
        void init();
        IParticleSystemSceneNode* particleNode;
        IParticleEmitter* particleEmitter;
        IParticleAffector* particleAffector;
        IrrlichtDevice* device;
        ISceneManager* manager;

};

#endif // PARTICLEMANAGER

