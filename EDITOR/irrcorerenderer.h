
//irrcorerenderer.h

#ifndef IRRCORERENDER_H
#define IRRCORERENDER_H

#include <QObject>
#include <QWidget>
#include "irrlicht.h"

using namespace irr;

class IrrCoreRenderer : public QWidget
{
    Q_OBJECT

public:
    IrrCoreRenderer(QWidget *irrRenderTarget, bool softwareRenderer);
    ~IrrCoreRenderer();
    void init();
    void resizeIrrWidget(int x, int y, int newWidth, int newHeight);

    void createParticle();
    void deleteParticle();
    float minScale;
    float maxScale;


    core::vector3di* dark;
    core::vector3di* bright;

private:
    QWidget *irrRenderTarget;
    video::E_DRIVER_TYPE rendererType;
    scene::ISceneManager* smgr;
    scene::IParticleSystemSceneNode* particleNode;
    scene::IParticleEmitter* particleEmitter;
    scene::IParticleAffector* particleAffector;



protected:
    SIrrlichtCreationParameters params;
    IrrlichtDevice* device;
    virtual void timerEvent(QTimerEvent* event);
};

#endif // IRRCORERENDER_H
