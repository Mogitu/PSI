
//irrcorerenderer.h

#ifndef IRRRENDERWIDGET_H
#define IRRRENDERWIDGET_H

#include <QObject>
#include <QWidget>
#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class IrrRenderWidget : public QWidget
{
    Q_OBJECT

public:
    IrrRenderWidget(QWidget *irrRenderTarget, bool softwareRenderer);
    ~IrrRenderWidget();
    void init();
    void resizeIrrWidget(int x, int y, int newWidth, int newHeight);

    void createParticle();    
    void createEmitter();
    float minScale;
    float maxScale;

    vector3di* dark;
    vector3di* bright;

private:
    QWidget *irrRenderTarget;
    E_DRIVER_TYPE rendererType;
    ISceneManager* smgr;
    IParticleSystemSceneNode* particleNode;
    IParticleEmitter* particleEmitter;
    IParticleAffector* particleAffector;



protected:
    SIrrlichtCreationParameters params;
    IrrlichtDevice* device;
    virtual void timerEvent(QTimerEvent* event);
};

#endif
